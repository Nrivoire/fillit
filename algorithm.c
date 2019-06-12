/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algorithm.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/05 16:37:50 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 19:29:53 by nrivoire    ###    #+. /#+    ###.fr     */
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

char			*del_letter(char *carre, char letter)
{
	int				i;
	char			tmp_letter;

	tmp_letter = letter;
	tmp_letter--;
	i = 0;
	while (carre[i] != '\0')
	{
		if (carre[i] == tmp_letter)
			carre[i] = '.';
		i++;
	}
	return (carre);
}

int				place_error(t_fillit *some, int start)
{
	int				y;
	int				n;
	int				x;
	int				tmp_i;

	n = 2;
	y = (int)some->begin_lst->t[1] - 48;
	while (y-- > 0)
	{
		x = (int)some->begin_lst->t[0] - 48;
		tmp_i = start;
		while (x-- > 0)
		{
			if (some->begin_lst->t[n++] == '@' && some->carre[tmp_i] != '.')
				return (-1);
			tmp_i++;
		}
		start = start + some->sq_area;
	}
	return (0);
}

char			*fill(t_fillit *some, int start)
{
	int				n;
	int				y;
	int				x;
	int				tmp_start;

	n = 2;
	y = (int)some->begin_lst->t[1] - 48;
	while (y-- > 0)
	{
		x = (int)some->begin_lst->t[0] - 48;
		tmp_start = start;
		while (x-- > 0)
		{
			if (some->begin_lst->t[n++] == '@' && some->carre[tmp_start] == '.')
				some->carre[tmp_start] = some->begin_lst->letter;
			tmp_start++;
		}
		start = start + some->sq_area;
	}
	return (some->carre);
}
