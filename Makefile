# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdonga <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/24 11:32:50 by pdonga            #+#    #+#              #
#    Updated: 2019/09/25 14:32:24 by pdonga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in.a

FLAGS = -Wall -Werror -Wextra -I. -c -g

SOURCES = start_command.c\
			end_command.c\
			ignore_command.c\
			command.c\
			is_link.c\
			free_farm.c\
			initialise_ants.c\
			create_ants.c\
			free_arr.c\
			validate_room.c\
			save_rooms.c\
			save_links.c\
			read_farm.c\
			initialise_every_room.c\
			number_of_ants.c\
			initialise_room.c\
			initialise_start_end.c\
			build_rooms.c\
			initialise_farm.c\
			check_start.c\
			check_end.c\
			check_start_end.c\
			validate_farm.c\
			error.c\
			exit_farm.c\
			print_rooms.c\
			print_ants.c\
			get_link.c\
			assign_links_to_room.c\
			count_links.c\
			assign_links.c

INCLUDE = lem_in.h

OBJECTS = $(SOURCES:%.c=%.o)

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SOURCES)
	@ar rv $(NAME) $(OBJECTS) $(INCLUDE)
	@ranlib $(NAME)
	@make -C ./libft
	gcc -o lem-in main.c lem_in.a ./libft/libft.a


make_libft:
	@make -C ./libft

clean:
	@rm -f $(OBJECTS)
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft
 
re: fclean all
