/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algorithm.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/05 16:37:50 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/05 16:38:11 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int				sq_len(int nb_te)
{
	int				sq_len;

	sq_len = ft_sqrt(nb_te * 4);
	return (sq_len);
}

char			*do_carre(int sq_area)
{
	char			*carre;

	carre = ft_strnew(sq_area * sq_area);
	ft_memset(carre, '.', (sq_area * sq_area));
	return (carre);
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
	int				tmp_i;

	n = 2;
	y = (int)cursor->t[1] - 48;
	while (y > 0)
	{
		x = (int)cursor->t[0] - 48;
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
