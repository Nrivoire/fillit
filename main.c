/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loatilem <loatilem@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/05 15:21:57 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 18:26:29 by loatilem    ###    #+. /#+    ###.fr     */
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

char			*del_letter(char *carre, char letter)
{
	int				i;

	i = 0;
	while (carre[i] != '\0')
	{
		if (carre[i] == letter)
			carre[i] = '.';
		i++;
	}
	return (carre);
}

int 		optimization(char *carre, int sq_area, char letter, t_fillit *some)
{
	int		start;
	t_ptr	*lst_elem;
	int		x;

	lst_elem = some->begin_lst;
	while (lst_elem->letter != letter)
			lst_elem = lst_elem->next;
	x = lst_elem->t[0] - 48;
	start = 0;
	while ((some->carre[start] != '\0'))
	{	
		if ((place_error(lst_elem, some->carre, start, sq_area) == -1 )|| ((start % sq_area) > (sq_area - x)))
			;
		else
		{
			some->carre = fill(start, lst_elem, some->carre, sq_area);
			if (lst_elem->letter == some->begin_lst->letter)
				return (1);
			letter++;
			if(optimization(some->carre, sq_area, letter, some))
				return (1);
			else
			{
				letter--;
				some->carre = del_letter(some->carre, letter);
			}
		}
		start++;
	}
	return (0);
}


t_fillit			*read_and_resolve(t_fillit *some, char **ac, int nb_te)
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
		some->begin_lst = addlst(some->begin_lst, compare(some->tmp, some), 'A' + nb_te++);
		free(some->tmp);
		read(fd, buff, 1);
	}
	some->nb_te = nb_te;
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
	int				sq_area;

	av = 2;
	nb_te = 0;
	enlarge = 0;
	start = 0;
	if (!(some = (t_fillit *)malloc(sizeof(t_fillit))))
		return (0);
	some = read_and_resolve(some, ac, nb_te);
	sq_area = sq_len(some->nb_te);
	some->carre = do_carre(sq_area);	
	while ((optimization(some->carre, sq_area, 'A', some) != 1) && sq_area < 13)
	{	
		sq_area++;
		some->carre = do_carre(sq_area);
	}
	print(some->carre, sq_area);
	return (0);
}
