/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 11:51:55 by nrivoire          #+#    #+#             */
/*   Updated: 2019/06/04 20:42:43 by nrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

void			ft_error(char *str)
{
	ft_putendl(str);
	exit(0);
}

int			check(char *buff)
{
	int				s;
	int				i;

	i = 0;
	s = 0;
	while (buff)
	{
		if (buff[s] != '.' && buff[s] != '#' && buff[s] != '\n')
			break ;
		if (buff[s] == '#')
			i++;
		s++;
	}
	if (!(i == 4 && s == 20 && buff[s - 1] == '\n'))
		ft_error("error");
	return (s);
}

void			form(int s, char *buff)
{
	int				pos;

	pos = 0;
	while (s >= 0)
	{
		if (buff[s] == '#')
		{
			if (s - 1 >= 0 && buff[s - 1] == '#')
				pos++;
			if (s - 5 >= 0 && buff[s - 5] == '#')
				pos++;
			if (s + 1 < 20 && buff[s + 1] == '#')
				pos++;
			if (s + 5 < 20 && buff[s + 5] == '#')
				pos++;
		}
		s--;
	}
	if (!(pos == 6 || pos == 8))
		ft_error("error");
}

void			storage(t_fillit *some)
{
	some->second[0] = "23@@@.@.";
	some->second[1] = "23@@.@.@";
	some->second[2] = "32@@@@..";
	some->second[3] = "32@@@..@";
	some->second[4] = "23@.@.@@";
	some->second[5] = "23.@.@@@";
	some->second[6] = "32@..@@@";
	some->second[7] = "32..@@@@";
	some->second[8] = "22@@@@";
	some->second[9] = "41@@@@";
	some->second[10] = "14@@@@";
	some->second[11] = "32@@..@@";
	some->second[12] = "23.@@@@.";
	some->second[13] = "23@.@@.@";
	some->second[14] = "32.@@@@.";
	some->second[15] = "32.@.@@@";
	some->second[16] = "23@.@@@.";
	some->second[17] = "32@@@.@.";
	some->second[18] = "23.@@@.@";
}

void			possibilities(t_fillit *some)
{
	some->first[0] = "##..#...#";
	some->first[1] = "##...#...#";
	some->first[2] = "###.#";
	some->first[3] = "###...#";
	some->first[4] = "#...#...##";
	some->first[5] = "#...#..##";
	some->first[6] = "#...###";
	some->first[7] = "#.###";
	some->first[8] = "##..##";
	some->first[9] = "####";
	some->first[10] = "#...#...#...#";
	some->first[11] = "##...##";
	some->first[12] = "#..##..#";
	some->first[13] = "#...##...#";
	some->first[14] = "##.##";
	some->first[15] = "#..###";
	some->first[16] = "#...##..#";
	some->first[17] = "###..##";
	some->first[18] = "#..##...#";
	storage(some);
}

char				*compare(char *buff, t_fillit *some)
{
	int				i;

	i = 0;
	while (i < 19)
	{
		if (ft_strstr(buff, some->first[i]) != NULL)
		{
			buff = ft_strcpy(buff, some->second[i]);
			break ;
		}
		i++;
	}
	return (buff);
}

int			sq_len(int nb_tetri)
{
	int				sq_len;

	sq_len = ft_sqrt(nb_tetri * 4);
	printf("%d\n", sq_len);
	return (sq_len);
}


char		*do_carre(int sq_area)
{
	char			*carre;

	carre = ft_strnew(sq_area * sq_area);
	ft_memset(carre, '.', (sq_area * sq_area));
	return 	(carre);
}
int				place_error(t_ptr *cursor, char *carre, int start, int sq_area)
{
	int				y;
	int				i;
	int				n;
	int				x;
	int				tmp_i;

	i = start;
	n = 2;
	y = (int)cursor->t[1] - 48;
	while (y > 0)
	{
		x = (int)cursor->t[0] - 48;
		tmp_i = i;
		while (x > 0)
		{
			if (cursor->t[n] == '@' && carre[tmp_i] != '.')
				return (-1);
			n++;
			tmp_i++;
			x--;
		}
		i = i + sq_area;
		y--;
	}
	return (start);
}

char			*fill(int i, t_ptr *cursor, char *carre, int sq_area)
{
	int				n;
	int				y;
	int				x;
	int 			tmp_i;

	n = 2;
	y = (int)cursor->t[1] - 48;
	
	while (y > 0)
	{
		x = (int)cursor->t[0] - 48;;
		tmp_i = i;
		while (x > 0)
		{
			if (cursor->t[n] == '@' && carre[tmp_i] == '.')
				carre[tmp_i] = cursor->letter;
			tmp_i++;
			n++;
			x--;
		}
		i = i + sq_area;
		y--;
	}
	return (carre);
}

char			*square(int nb_tetri, int sq_area, t_ptr *begin_lst)
{
	char			letter;
	char			*carre;
	t_ptr			*cursor;
	int				start;
	int				x;

	letter = 'A';
	carre = do_carre(sq_area);
	while (letter <= nb_tetri + 64)
	{
		cursor = begin_lst;
		while (cursor->letter != letter)
			cursor = cursor->next;
		start = 0;
		x = (int)cursor->t[0] - 48;
		while ((place_error(cursor, carre, start, sq_area) == -1) || ((start % sq_area) > (sq_area - x)))
		{
			if (start > sq_area *sq_area)
				 break ; 
			start++;
		}
		carre = fill(start, cursor, carre, sq_area);
		letter++;
	}
	printf("carre = %s\n", carre);
	return (carre);
}

int				main(int av, char **ac)
{
	int				fd;
	char			buff[BUFF_SIZE + 1];
	int				ret;
	char			*tmp;
	int				nb_tetri;
	t_fillit		*some;

	av = 2;
	nb_tetri = 0;
	fd = open(ac[1], O_RDONLY);
	if (!(some = (t_fillit *)malloc(sizeof(t_fillit))))
		return (0);
	possibilities(some);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0 && nb_tetri < 27)
	{
		buff[ret] = '\0';
		form(check(buff), buff);
		tmp = ft_stractrim(buff, '\n');
		some->list = add_to_front_lst(some->list, compare(tmp, some), 'A' + nb_tetri++);
		free(tmp);
		read(fd, buff, 1);
	}
	if (nb_tetri >= 27)
		ft_error("error");
	ret = 0;
	while (sq_len(nb_tetri + ret) <= 13)
	{
		square(nb_tetri + ret, sq_len(nb_tetri + ret), some->list);
	 	ret++;
	}
	//print_lst(some->list);
	return (0);
}