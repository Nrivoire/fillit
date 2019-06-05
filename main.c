/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/05 15:21:57 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/05 20:06:24 by nrivoire    ###    #+. /#+    ###.fr     */
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

int				fill_start(int start, char *carre, int sq_len, t_ptr *cursor)
{
	int				x;

	x = (int)cursor->t[0] - 48;
	while ((place_error(cursor, carre, start, sq_len) == -1)
		|| ((start % sq_len) > (sq_len - x)))
	{
		if (start > sq_len * sq_len)
			return (-1);
		start++;
	}
	//carre = fill(start, cursor, carre, sq_len);
	return (start);
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

char			*enlarge_sq(char *carre, int sq_len)
{
	free(carre);
	carre = NULL;
	carre = do_carre(sq_len);
	return (carre);
}

char			*optimization(char *carre, char letter, t_ptr *cursor, int start, int sq_len)
{
	int				tmp_start;

	printf("letter %c, piece letter = %c\n", letter, cursor->letter);
	tmp_start = start;
	if (fill_start(start, carre, sq_len, cursor) != -1)
		carre = fill(fill_start(start, carre, sq_len, cursor), cursor, carre, sq_len);
	if (fill_start(start, carre, sq_len, cursor) == -1)
	{
		carre = del_letter(carre, letter);
		return(optimization(carre, 'A', cursor, start++, sq_len));
	}
	if (letter < cursor->letter)
	{
		letter++;
		return(optimization(carre, letter, cursor, start, sq_len));
	}
	if (letter == 'A' && fill_start(start, carre, sq_len, cursor) == -1)
	{
		sq_len++;
		return(optimization(enlarge_sq(carre, sq_len), letter, cursor, start, sq_len));
	}
	return (carre);
}

char			*sq(int sq_len, t_ptr *begin_lst)
{
	char			*carre;
	int				start;

	start = 0;
	carre = do_carre(sq_len);
	carre = optimization(carre, 'A', begin_lst, start, sq_len);
	return (carre);	
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
	if (nb_te >= 27)
		ft_error("error");
	ret = 0;
	// while (ft_strcmp(sq(sq_len(nb_te + ret), some->begin_lst), "small") == 0)
	// 	ret++;
	print(sq(sq_len(nb_te + ret), some->begin_lst), sq_len(nb_te + ret));
	return (some);
}

int				main(int av, char **ac)
{
	int				nb_te;
	t_fillit		*some;

	av = 2;
	nb_te = 0;
	if (!(some = (t_fillit *)malloc(sizeof(t_fillit))))
		return (0);
	some = read_and_resolve(some, ac, nb_te);
	return (0);
}
