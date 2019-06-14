/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algorithm.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/05 16:37:50 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/14 17:35:43 by nrivoire    ###    #+. /#+    ###.fr     */
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

char			*do_square(t_fillit *some)
{
	if (!(some->square = ft_strnew(some->map_size)))
		ft_error("error");
	ft_memset(some->square, '.', some->map_size);
	return (some->square);
}

char			*del_letter(char *square, char letter)
{
	int			i;
	int			tmp;

	i = -1;
	tmp = ft_strlen(square);
	while (++i < tmp)
		if (square[i] == letter)
			square[i] = '.';
	return (square);
}

int				place_error(t_fillit *some, int start)
{
	int				y;
	size_t			n;
	int				x;
	int				tmp_i;

	n = 2;
	y = some->second[some->lst->number][1] - 48;
	while (y-- > 0)
	{
		x = some->second[some->lst->number][0] - 48;
		tmp_i = start;
		while (x-- > 0)
			if ((some->second[some->lst->number][n++] == '@' 	\
					&& (some->square[tmp_i] != '.')) 				\
					|| tmp_i++ >= some->map_size)
				return (-1);
		if ((start += some->sq_area) > some->map_size)
			start = some->map_size;
	}
	return (0);
}

void			fill(t_fillit *some, int start)
{
	int				n;
	int				y;
	int				x;
	int				tmp_i;

	n = 2;
	y = some->second[some->lst->number][1] - 48;
	while (y-- > 0)
	{
		x = some->second[some->lst->number][0] - 48;
		tmp_i = start;
		while (x-- > 0)
		{
			if (some->second[some->lst->number][n++] == '@' 	\
					&& some->square[tmp_i] == '.')
				some->square[tmp_i] = some->lst->letter;
			tmp_i++;
		}
		start += some->sq_area;
	}
}
