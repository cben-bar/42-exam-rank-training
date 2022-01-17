# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 17:54:31 by cben-bar          #+#    #+#              #
#    Updated: 2021/11/18 02:26:33 by cben-bar         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

SRCS		=	ft_atoi.c			\
				ft_bzero.c			\
				ft_calloc.c			\
				ft_isalnum.c		\
				ft_isalpha.c		\
				ft_isascii.c    	\
				ft_isdigit.c		\
				ft_isprint.c   		\
				ft_itoa.c			\
				ft_memchr.c			\
				ft_memcmp.c			\
				ft_memcpy.c			\
				ft_memmove.c		\
				ft_memset.c			\
				ft_putchar_fd.c		\
				ft_putendl_fd.c		\
				ft_putnbr_fd.c		\
				ft_putstr_fd.c		\
				ft_split.c			\
				ft_strchr.c			\
				ft_strdup.c			\
				ft_striteri.c		\
				ft_strjoin.c		\
				ft_strlcat.c		\
				ft_strlcpy.c		\
				ft_strlen.c			\
				ft_strmapi.c		\
				ft_strncmp.c		\
				ft_strnstr.c		\
				ft_strrchr.c		\
				ft_strtrim.c		\
				ft_substr.c			\
				ft_tolower.c		\
				ft_toupper.c

BON			=	ft_lstadd_front.c	\
				ft_lstnew.c			\
				ft_lstsize.c		\
				ft_lstlast.c		\
				ft_lstadd_back.c	\
				ft_lstdelone.c		\
				ft_lstclear.c		\
				ft_lstiter.c		\
				ft_lstmap.c

OBJS		= 	$(SRCS:.c=.o)

BON_OBJS	= 	$(BON:.c=.o) 

all :			$(NAME)

$(NAME)	:		$(OBJS) 
				ar rcs $(NAME) ${OBJS}

%.o:			%.c libft.h
				$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

clean :
				rm -f $(OBJS) $(BON_OBJS)

fclean :		clean
				rm -f $(NAME)

re :			fclean all

bonus :			$(NAME) $(BON_OBJS)
				ar rcs $(NAME) $(BON_OBJS) 

.PHONY :		all clean fclean re bonus
