/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/05 15:21:45 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/05 17:25:30 by nrivoire    ###    #+. /#+    ###.fr     */
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
	char				*t;
	char				letter;
	struct s_tetri		*next;
}					t_ptr;

typedef struct		s_fillit
{
	char				*first[19];
	char				*second[19];
	t_ptr				*lst;
	char				*tmp;
}					t_fillit;

void			ft_error(char *str);
int				check(char *buff);
void			form(int s, char *buff);
void			storage(t_fillit *some);
void			possibilities(t_fillit *some);
char			*compare(char *buff, t_fillit *some);
t_ptr			*lstnew(void const *content, char letter);
t_ptr			*addlst(t_ptr *begin_lst, void *data, char letter);
int				sq_len(int nb_te);
char			*do_carre(int sq_area);
int				place_error(t_ptr *cursor, char *carre, int start, int sq_area);
char			*fill(int i, t_ptr *cursor, char *carre, int sq_area);

#endif
