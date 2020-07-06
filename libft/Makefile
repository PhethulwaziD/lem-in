# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdonga <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/05 11:29:37 by pdonga            #+#    #+#              #
#    Updated: 2019/09/03 11:38:14 by pdonga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra -I. -c

SOURCES =	ft_isascii.c ft_memcpy.c ft_putendl_fd.c ft_strclr.c ft_strjoin.c ft_strnequ.c ft_tolower.c\
			ft_isdigit.c ft_isint.c ft_memdel.c ft_putnbr.c ft_strcmp.c ft_strlcat.c ft_strnew.c ft_toupper.c\
			ft_atoi.c ft_isprint.c ft_memmove.c ft_putnbr_fd.c ft_strcpy.c ft_strlen.c ft_strnstr.c ft_trimch.c\
			ft_bzero.c ft_itoa.c ft_memset.c ft_putstr.c ft_strdel.c ft_strmap.c ft_strrchr.c ft_wordcount.c\
			ft_chcmp.c ft_memalloc.c ft_pow.c ft_putstr_fd.c ft_strdup.c ft_strmapi.c ft_strsplit.c\
			ft_escape.c	ft_memccpy.c ft_putchar.c ft_split.c ft_strequ.c ft_strncat.c ft_strstr.c get_next_line.c\
			ft_isalnum.c ft_memchr.c ft_putchar_fd.c ft_strcat.c ft_striter.c ft_strncmp.c ft_strsub.c\
			ft_isalpha.c ft_memcmp.c ft_putendl.c ft_strchr.c ft_striteri.c ft_strncpy.c ft_strtrim.c ft_absolute.c

INCLUDE = libft.h

OBJECTS = $(SOURCES:%.c=%.o)

all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) $(SOURCES)
	@ar rv $(NAME) $(OBJECTS) $(INCLUDE)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

