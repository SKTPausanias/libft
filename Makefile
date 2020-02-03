# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 15:21:51 by mlaplana          #+#    #+#              #
#    Updated: 2019/12/06 17:15:44 by mlaplana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c	ft_bzero.c	ft_calloc.c		\
	   ft_isalnum.c		ft_isalpha.c	ft_isascii.c	\
	   ft_isdigit.c		ft_isprint.c	ft_itoa.c		\
	   ft_memccpy.c		ft_memchr.c		ft_memcmp.c		\
	   ft_memcpy.c		ft_memmove.c	ft_memset.c		\
	   ft_putchar_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c	\
	   ft_putstr_fd.c	ft_split.c		ft_strchr.c		\
	   ft_strdup.c		ft_strjoin.c	ft_strlcat.c	\
	   ft_strlcpy.c		ft_strlen.c		ft_strmapi.c	\
	   ft_strncmp.c		ft_strnstr.c	ft_strrchr.c	\
	   ft_strtrim.c		ft_substr.c		ft_tolower.c	\
	   ft_toupper.c		ft_checkflags.c ft_condaux.c	\
	   ft_itoa_hex.c	ft_itoa_unsigned.c	ft_printcs.c \
	   ft_printdiu.c	ft_printf.c		ft_printx.c	\
	   ft_put.c			ft_zerosandspaces.c	get_next_line_bonus.c \

BONUS =  ft_lstadd_back_bonus.c		ft_lstadd_front_bonus.c		ft_lstclear_bonus.c	\
		 ft_lstdelone_bonus.c	ft_lstiter_bonus.c	ft_lstlast_bonus.c	\
		 ft_lstmap_bonus.c	ft_lstnew_bonus.c	ft_lstsize_bonus.c

OBJS = $(SRC:.c=.o)

BONUSO = ft_lstadd_back_bonus.o	ft_lstadd_front_bonus.o	ft_lstclear_bonus.o	\
		 ft_lstdelone_bonus.o	ft_lstiter_bonus.o	ft_lstlast_bonus.o	\
		 ft_lstmap_bonus.o	ft_lstnew_bonus.o	ft_lstsize_bonus.o

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)
	
$(NAME) :
	gcc $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)	

bonus :
	gcc $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)	
	gcc $(CFLAGS) -c $(BONUS)
	ar rc $(NAME) $(BONUSO)
	ranlib $(NAME)

clean :
	rm -f *.o

fclean:		clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean bonus