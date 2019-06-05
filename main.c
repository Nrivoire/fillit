/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/05 15:21:57 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/05 17:25:29 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

char			*place_and_fill(int start, char *carre, int sq_area, t_ptr *cursor)
{
	int				x;

	x = (int)cursor->t[0] - 48;
	while ((place_error(cursor, carre, start, sq_area) == -1)
		|| ((start % sq_area) > (sq_area - x)))
	{
		if (start > sq_area * sq_area)
		{
			free(carre);
			carre = NULL;
			return ("small");
		}
		start++;
	}
	carre = fill(start, cursor, carre, sq_area);
	return (carre);
}

char			*sq(int nb_te, int sq_area, t_ptr *begin_lst)
{
	char			letter;
	char			*carre;
	t_ptr			*cursor;
	int				start;

	letter = 'A';
	carre = do_carre(sq_area);
	while (letter <= nb_te + 64)
	{
		cursor = begin_lst;
		while (cursor->letter != letter)
			cursor = cursor->next;
		start = 0;
		carre = place_and_fill(start, carre, sq_area, cursor);
		letter++;
	}
	return (carre);
}

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
		some->lst = addlst(some->lst, compare(some->tmp, some), 'A' + nb_te++);
		free(some->tmp);
		read(fd, buff, 1);
	}
	if (nb_te >= 27)
		ft_error("error");
	ret = 0;
	while (ft_strcmp(sq(nb_te, sq_len(nb_te + ret), some->lst), "small") == 0)
		ret++;
	print(sq(nb_te, sq_len(nb_te + ret), some->lst), sq_len(nb_te + ret));
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
