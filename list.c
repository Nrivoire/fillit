/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   list.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/05 15:22:14 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/14 14:53:08 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

t_ptr			*lstnew(void const *content, char letter)
{
	t_ptr		*elem;

	if (!(elem = (t_ptr *)malloc(sizeof(t_ptr))))
		return (NULL);
	if (content)
	{
		if (!(elem->t = (void *)malloc(sizeof(char) * 16)))
			return (NULL);
		ft_memcpy(elem->t, content, 21);
		elem->letter = letter;
	}
	else
		elem->t = NULL;
	elem->next = NULL;
	return (elem);
}

t_ptr			*addlst(t_ptr *begin_lst, void *data, char letter)
{
	t_ptr	*new;
	t_ptr	*tmp;

	if (begin_lst != NULL)
	{
		new = lstnew(data, letter);
		tmp = begin_lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->next = NULL;
	}
	else
		begin_lst = lstnew(data, letter);
	return (begin_lst);
}

void			storage(t_fillit *some)
{
	some->second[0] = "23@@@.@.";
	some->second[1] = "23@@.@.@";
	some->second[2] = "32@@@@..";
	some->second[3] = "32@@@..@";
	some->second[4] = "23@.@.@@";
	some->second[5] = "23.@.@@@";
	some->second[6] = "32@..@@@";
	some->second[7] = "32..@@@@";
	some->second[8] = "22@@@@";
	some->second[9] = "41@@@@";
	some->second[10] = "14@@@@";
	some->second[11] = "32@@..@@";
	some->second[12] = "23.@@@@.";
	some->second[13] = "23@.@@.@";
	some->second[14] = "32.@@@@.";
	some->second[15] = "32.@.@@@";
	some->second[16] = "23@.@@@.";
	some->second[17] = "32@@@.@.";
	some->second[18] = "23.@@@.@";
}

void			possibilities(t_fillit *some)
{
	some->first[0] = "##..#...#";
	some->first[1] = "##...#...#";
	some->first[2] = "###.#";
	some->first[3] = "###...#";
	some->first[4] = "#...#...##";
	some->first[5] = "#...#..##";
	some->first[6] = "#...###";
	some->first[7] = "#.###";
	some->first[8] = "##..##";
	some->first[9] = "####";
	some->first[10] = "#...#...#...#";
	some->first[11] = "##...##";
	some->first[12] = "#..##..#";
	some->first[13] = "#...##...#";
	some->first[14] = "##.##";
	some->first[15] = "#..###";
	some->first[16] = "#...##..#";
	some->first[17] = "###..##";
	some->first[18] = "#..##...#";
	storage(some);
}

char			*compare(char *buff, t_fillit *some)
{
	int				i;

	i = 0;
	while (i < 19)
	{
		if (ft_strstr(buff, some->first[i]) != NULL)
		{
			buff = ft_strcpy(buff, some->second[i]);
			break ;
		}
		i++;
	}
	return (buff);
}
