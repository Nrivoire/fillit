/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/05 15:21:45 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/17 21:43:50 by nrivoire    ###    #+. /#+    ###.fr     */
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
# include "libft/libft.h"

typedef struct		s_tetri
{
	char			*t;
	char			letter;
	int				number;
	struct s_tetri	*next;
}					t_ptr;

typedef struct		s_fillit
{
	char			*first[19];
	char			*second[19];
	char			*square;
	t_ptr			*lst;
	int				nb_te;
	int				sq_area;
	int				map_size;
}					t_fillit;

/*
** main.c
*/
void				print(char *square, int sq_len);

/*
** read.c
*/
t_ptr				*seach_lst(t_fillit *some, char letter);
int					optimization(t_fillit *some);
t_fillit			*read_fillit(t_fillit *some, char **ac, int nb_te);

/*
** list.c
*/
t_ptr				*addlst(t_ptr *lst, int number, char letter);
void				storage(t_fillit *some);
void				possibilities(t_fillit *some);
int					compare(char *buff, t_fillit *some);
void				lstdel(t_ptr *lst);

/*
** algorithm.c
*/
int					sq_len(int nb_te);
char				*do_square(t_fillit *some);
char				*del_letter(char *square, char letter);
int					place_error(t_fillit *some, int start);
void				fill(t_fillit *some, int start);

/*
** check.c
*/
void				ft_error(char *str);
void				check(char *buff);
void				correct_form(char *buff);

#endif
