/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/13 16:48:10 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/17 21:43:41 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int				optimization(t_fillit *some)
{
	int		start;
	int		x;
	t_ptr	*tmp;

	start = -1;
	if (!some->lst)
		return (1);
	x = (int)some->second[some->lst->number][0] - 48;
	while ((some->square[++start] != '\0'))
		if (!((place_error(some, start) == -1) ||
			((start % some->sq_area) > (some->sq_area - x))))
		{
			fill(some, start);
			tmp = some->lst;
			some->lst = some->lst->next;
			if (optimization(some))
				return (1);
			some->lst = tmp;
			some->square = del_letter(some->square, some->lst->letter);
		}
	return (0);
}

t_fillit		*read_fillit(t_fillit *some, char **ac, int nb_te)
{
	char			buff[BUFF_SIZE + 1];
	int				ret;
	int				fd;
	char			*tmp;

	if ((fd = open(ac[1], O_RDONLY)) < 0)
		ft_error("error");
	possibilities(some);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0 && nb_te < 27)
	{
		buff[ret] = '\0';
		check(buff);
		correct_form(buff);
		if (!(tmp = ft_stractrim(buff, '\n')))
			ft_error("error");
		some->lst = addlst(some->lst, compare(tmp, some), 'A' + nb_te++);
		free(tmp);
		read(fd, buff, 1);
	}
	close(fd);
	some->nb_te = nb_te;
	some->sq_area = sq_len(some->nb_te);
	if (nb_te >= 27)
		ft_error("error");
	return (some);
}
