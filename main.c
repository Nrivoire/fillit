/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/05 15:21:57 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/25 13:24:55 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void			print(char *square, int sq_len)
{
	int				i;

	i = 0;
	while (square[i] != '\0')
	{
		ft_putchar(square[i]);
		i++;
		if (i % sq_len == 0)
			ft_putchar('\n');
	}
}

void			make_map(t_fillit *some)
{
	t_ptr			*tmp;

	some->map_size = some->sq_area * some->sq_area;
	do_square(some);
	tmp = some->lst;
	while ((optimization(some) != 1) && some->sq_area < 13)
	{
		some->map_size = ++some->sq_area * some->sq_area;
		free(some->square);
		do_square(some);
	}
	lstdel(tmp);
}

int				main(int av, char **ac)
{
	int				nb_te;
	t_fillit		*some;

	if (av != 2)
		ft_error("usage : ./fillit sample_fillit");
	nb_te = 0;
	if (!(some = (t_fillit *)malloc(sizeof(t_fillit))))
		return (0);
	some->lst = NULL;
	some = read_fillit(some, ac, nb_te);
	make_map(some);
	print(some->square, some->sq_area);
	free(some->square);
	free(some);
	return (0);
}
