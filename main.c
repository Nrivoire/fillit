/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/05 15:21:57 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/14 15:33:18 by nrivoire    ###    #+. /#+    ###.fr     */
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

int				main(int av, char **ac)
{
	int				nb_te;
	int				enlarge;
	t_fillit		*some;

	av = 2;
	nb_te = 0;
	enlarge = 0;
	if (!(some = (t_fillit *)malloc(sizeof(t_fillit))))
		return (0);
	some = read_fillit(some, ac, nb_te);
	some->carre = do_carre(some->sq_area);
	while ((optimization(some, some->begin_lst) != 1) && some->sq_area < 13)
	{
		some->sq_area++;
		some->carre = do_carre(some->sq_area);
	}
	print(some->carre, some->sq_area);
	return (0);
}
