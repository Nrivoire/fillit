/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/13 16:48:10 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/14 14:49:32 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int				optimization(t_fillit *some, t_ptr *lst_elem)
{
	int		start;
	int		x;

	start = -1;
	if (lst_elem == NULL)
		return (1);
	//print(some->carre, some->sq_area);
	x = (int)lst_elem->t[0] - 48;
	//usleep(300000);
	//printf("\n");
	while ((some->carre[++start] != '\0'))
	{
		if (!((place_error(lst_elem, some, start) == -1) ||
			((start % some->sq_area) > (some->sq_area - x))))
		{
			some->carre = fill(lst_elem, some, start);
			//printf("%s\n\n", some->carre);
			if (optimization(some, lst_elem->next))
				return (1);
			else
				some->carre = del_letter(some->carre, lst_elem->letter);
		}
	}
	return (0);
}

t_fillit		*read_fillit(t_fillit *some, char **ac, int nb_te)
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
