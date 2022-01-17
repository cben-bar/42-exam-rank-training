# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 22:55:40 by cben-bar          #+#    #+#              #
#    Updated: 2022/01/17 22:58:52 by cben-bar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

FILES			= \
					ft_printf2.c			\
					ft_printc2.c			\
					ft_printstr2.c		\
					ft_printnbr2.c		\
					ft_printunsnbr2.c	\
					ft_printaddr2.c		\
					ft_printhexnbr2.c

SRCS_DIR		=	./srcs/

SRCS			=	$(addprefix $(SRCS_DIR),$(FILES))

OBJ				=	$(SRCS:.c=.o)

CFLAGS 			=	-Wall -Wextra -Werror

all : 				$(NAME)

%.o: %.c 			./includes/ft_printf.h
					gcc $(CFLAGS) -c $< -o $@

$(NAME) :			$(OBJ)
					make -C ./libft
					cp ./libft/libft.a $(NAME)
					ar -rc $(NAME) $(OBJ)

clean :
					make -C ./libft clean
					/bin/rm -rf $(OBJ)

fclean :			clean
					/bin/rm -rf libftprintf.a
					/bin/rm -rf libft/libft.a
					/bin/rm -rf $(NAME)

re :				fclean all

.PHONY:				all clean fclean re
