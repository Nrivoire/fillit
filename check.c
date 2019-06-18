/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/05 16:29:06 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/18 18:45:39 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void			ft_error(char *str)
{
	ft_putendl(str);
	exit(0);
}

void			check(char *buff)
{
	if (!(ft_occur(buff, '.') == 12 && ft_occur(buff, '#') == 4 	\
			&& (ft_occur(buff, '\n') == 4 || ft_occur(buff, '\n') == 5)))
		ft_error("error");
}

void			correct_form(char *buff)
{
	int		n;
	int		s;
	int		c;

	n = 1;
	s = 0;
	c = 0;
	while (buff[s])
	{
		if (buff[s] == '\n' && s + 5 < 20 && buff[s + 5] == '\n')
			n++;
		s++;
	}
	if (!(n == 4))
		ft_error("error");
}
