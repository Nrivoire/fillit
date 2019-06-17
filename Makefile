# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/06/14 18:19:22 by nrivoire     #+#   ##    ##    #+#        #
#    Updated: 2019/06/17 20:05:31 by nrivoire    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

# empêche le Makefile de confondre un fichier et une règle en cas de même nom
.PHONY: all clean fclean re

#################
##  VARIABLES  ##
#################

#	Output
NAME = fillit

#	Sources
SRC = main.c list.c read.c check.c algorithm.c \

#	Objects
OBJ = $(SRC:.c=.o)

#	Includes
CPPFLAGS = -Iinclude
LDFLAGS = -Llibft
LDLIBS = -lft

#	Compiler
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I. -c

################
##   COLORS   ##
################

GREY=$ \x1b[30m
RED=$ \x1b[31m
GREEN=$ \x1b[32m
YELLOW=$ \x1b[33m
BLUE=$ \x1b[34m
PINK=$ \x1b[35m
CYAN=$ \x1b[36m
WHITE=$ \x1b[37m

# This is a minimal set of ANSI/VT100 color codes
END=$ \x1b[0m
BOLD=$ \x1b[1m
UNDER=$ \x1b[4m
SUR=$ \x1b[7m

#################
##  TARGETS    ##
#################

# $@ -> nom de la règle
# $^ -> représente tout ce qui est apres le :
# $< -> nom de la dependance

all: $(NAME)

$(NAME): $(OBJ)
	@ $(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

%.o: %.c $(CPPFLAGS)
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@ /bin/rm -fv $(OBJ)

fclean: clean
	@ /bin/rm -fv $(NAME)
	@echo "$(BOLD) $(RED) [DONE] $(END) MAKEFILE CLEANING"

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

re: fclean all