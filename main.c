/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/05 15:21:57 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/06 15:53:40 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

void			print(char *carre, int sq_len)
{
	int				i;

	i = 0;
	while (carre[i] != '\0')
	{
		ft_putchar(carre[i]);
		i++;
		if (i % sq_len == 0)
			ft_putchar('\n');
	}
}

char			*del_letter(char *carre, char letter)
{
	int				i;

	i = 0;
	while (carre[i] != '\0')
	{
		if (carre[i] == letter - 1)
			carre[i] = '.';
		i++;
	}
	return (carre);
}

int				optimization(char letter, t_fillit *some, int start, int sq_area)
{
	t_ptr			*cursor;

	while (letter <= some->begin_lst->letter)
	{
		cursor = some->begin_lst;
		while (cursor->letter != letter)
			cursor = cursor->next;
		//printf("start = %d letter = %c\n", start, cursor->letter);
		if (place_error(cursor, some->carre, start, sq_area) == -1)
		{
			printf("place_error = %d\n", place_error(cursor, some->carre, start, sq_area));
			if (start > sq_area * sq_area && letter != 'A')
			{
				//letter--;

				del_letter(some->carre, letter--);
				//printf("LETR = %c\n", letter);
				printf("carre = %s\n\n", some->carre);
				return (0);
				//optimization(letter, some, start++, sq_area);
			}
			if (start > sq_area * sq_area && letter == 'A')
			{
				start = 0;
				printf("start = %d\n", start);
				return (-1);
			}
			printf("start = %d\n", start);
			printf("LETTER = %c\n", letter);
			
			optimization(letter, some, start, sq_area);
			start++;
		}
		start = place_error(cursor, some->carre, start, sq_area);
		some->carre = fill(start, cursor, some->carre, sq_area);
		letter++;
	}
	return (1);
}

t_fillit			*read_and_resolve(t_fillit *some, char **ac, int nb_te)
{
	char			buff[BUFF_SIZE + 1];
	int				ret;
	int				fd;

	fd = open(ac[1], O_RDONLY);
	possibilities(some);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0 && nb_te < 27)
	{
		buff[ret] = '\0';
		form(check(buff), buff);
		some->tmp = ft_stractrim(buff, '\n');
		some->begin_lst = addlst(some->begin_lst, compare(some->tmp, some), 'A' + nb_te++);
		free(some->tmp);
		read(fd, buff, 1);
	}
	some->nb_te = nb_te;
	if (nb_te >= 27)
		ft_error("error");
	return (some);
}

int				main(int av, char **ac)
{
	int				nb_te;
	int				enlarge;
	t_fillit		*some;
	int				start;

	av = 2;
	nb_te = 0;
	enlarge = 0;
	start = 0;
	if (!(some = (t_fillit *)malloc(sizeof(t_fillit))))
		return (0);
	some = read_and_resolve(some, ac, nb_te);
	some->carre = do_carre(sq_len(some->nb_te));
	while (optimization('A', some, start, sq_len(some->nb_te + enlarge)) != 1 && enlarge <= 13)
	{
		printf("nb_tetri = %d\n", some->nb_te);
		some->carre = do_carre(sq_len(some->nb_te + enlarge));
		enlarge++;
	}
	print(some->carre, sq_len(some->nb_te + enlarge));
	return (0);
}
