# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/26 10:58:53 by ilchahbi          #+#    #+#              #
#    Updated: 2024/06/08 14:24:02 by ilchahbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

MAKE = make

CFLAGS = -Wall -Wextra -Werror -g 

HEADER = push_swap.h

SRC = 	algo_utils.c filling.c free_fun.c ft_atoi.c ft_split.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_utils3.c lst_utils.c lst_utils2.c node_inx.c parsing.c push_movez.c push_swap.c read_args.c rev_rot_movez.c rot_movez.c sort_func.c swap_movez.c

MAN_OBJ = push_swap.o

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(MAN_OBJ)
	$(CC) $^ -o $@

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) -f $(OBJ) $(MAN_OBJ) 

fclean : clean
	rm -f $(NAME) 

re : fclean all

.PHONY : all clean fclean re 