/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 11:53:53 by nrivoire          #+#    #+#             */
/*   Updated: 2019/06/04 11:54:59 by nrivoire         ###   ########.fr       */
/*                                                                            */
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

t_ptr			*add_to_front_lst(t_ptr *begin_lst, void *data, char letter)
{
	t_ptr *new;

	if (begin_lst != NULL)
	{
		new = lstnew(data, letter);
		new->next = begin_lst;
		begin_lst = new;
	}
	else
		begin_lst = lstnew(data, letter);
	return (begin_lst);
}

void			print_lst(t_ptr *begin_lst)
{
	t_ptr *cursor;

	cursor = begin_lst;
	while (cursor != NULL)
	{
		ft_putstr((char *)cursor->t);
		cursor = cursor->next;
		ft_putchar('\n');
	}
}
