/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 11:52:30 by nrivoire          #+#    #+#             */
/*   Updated: 2019/06/04 16:53:11 by nrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 20

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include "src/libft/libft.h"

typedef struct		s_tetri
{
	char				*t;
	char				letter;
	struct s_tetri		*next;
}					t_ptr;

typedef struct		s_fillit
{
	char				*first[19];
	char				*second[19];
	t_ptr				*list;
}					t_fillit;

t_ptr			*lstnew(void const *content, char letter);
t_ptr			*add_to_front_lst(t_ptr *begin_lst, void *data, char letter);

//fonctions pour tester et a virer quand c'est fini
void			print_lst(t_ptr *begin_lst);

#endif
