/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/05 16:29:06 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/05 16:31:53 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void			ft_error(char *str)
{
	ft_putendl(str);
	exit(0);
}

int				check(char *buff)
{
	int				s;
	int				i;

	i = 0;
	s = 0;
	while (buff)
	{
		if (buff[s] != '.' && buff[s] != '#' && buff[s] != '\n')
			break ;
		if (buff[s] == '#')
			i++;
		s++;
	}
	if (!(i == 4 && s == 20 && buff[s - 1] == '\n'))
		ft_error("error");
	return (s);
}

void			form(int s, char *buff)
{
	int				pos;

	pos = 0;
	while (s >= 0)
	{
		if (buff[s] == '#')
		{
			if (s - 1 >= 0 && buff[s - 1] == '#')
				pos++;
			if (s - 5 >= 0 && buff[s - 5] == '#')
				pos++;
			if (s + 1 < 20 && buff[s + 1] == '#')
				pos++;
			if (s + 5 < 20 && buff[s + 5] == '#')
				pos++;
		}
		s--;
	}
	if (!(pos == 6 || pos == 8))
		ft_error("error");
}
