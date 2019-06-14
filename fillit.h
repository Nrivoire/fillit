/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/05 15:21:45 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/14 14:37:20 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
	char			*t;
	char			letter;
	struct s_tetri	*next;
}					t_ptr;

typedef struct		s_fillit
{
	char			*first[19];
	char			*second[19];
	char			*carre;
	t_ptr			*begin_lst;
	char			*tmp;
	int				nb_te;
	int				sq_area;
}					t_fillit;

/*
** main.c
*/
void				print(char *carre, int sq_len);

/*
** read.c
*/
t_ptr				*seach_lst(t_fillit *some, char letter);
int					optimization(t_fillit *some, t_ptr *lst_elem);
t_fillit			*read_fillit(t_fillit *some, char **ac, int nb_te);

/*
** list.c
*/
t_ptr				*lstnew(void const *content, char letter);
t_ptr				*addlst(t_ptr *begin_lst, void *data, char letter);
void				storage(t_fillit *some);
void				possibilities(t_fillit *some);
char				*compare(char *buff, t_fillit *some);

/*
** algorithm.c
*/
int					sq_len(int nb_te);
char				*do_carre(int sq_area);
char				*del_letter(char *carre, char letter);
int					place_error(t_ptr *lst_elem, t_fillit *some, int start);
char				*fill(t_ptr *cursor, t_fillit *some, int startx);

/*
** check.c
*/
void				ft_error(char *str);
int					check(char *buff);
void				form(int s, char *buff);

#endif
