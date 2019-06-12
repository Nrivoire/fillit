/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/05 15:21:57 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 19:29:14 by nrivoire    ###    #+. /#+    ###.fr     */
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

int				optimization(t_fillit *some, char letter)
{
	int		start;
	int		x;

	x = some->begin_lst->t[0] - 48;
	start = 0;
	while ((some->carre[start] != '\0'))
	{
		if ((place_error(some, start) == -1) ||
			((start % some->sq_area) > (some->sq_area - x)))
			;
		else
		{
			some->carre = fill(some, start);
			if (some->begin_lst->next == NULL)
				return (1);
			some->begin_lst = some->begin_lst->next;
			if (optimization(some, letter))
				return (1);
			else
				some->carre = del_letter(some->carre, some->begin_lst->letter);
		}
		start++;
	}
	return (0);
}

t_fillit		*read_and_resolve(t_fillit *some, char **ac, int nb_te)
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
		some->begin_lst = addlst(some->begin_lst,
						compare(some->tmp, some), 'A' + nb_te++);
		free(some->tmp);
		read(fd, buff, 1);
	}
	some->nb_te = nb_te;
	some->sq_area = sq_len(some->nb_te);
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
	some->carre = do_carre(some->sq_area);
	while ((optimization(some, 'A') != 1) && some->sq_area < 13)
	{
		some->sq_area++;
		some->carre = do_carre(some->sq_area);
	}
	print(some->carre, some->sq_area);
	return (0);
}
