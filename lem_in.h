/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 11:20:09 by pdonga            #+#    #+#             */
/*   Updated: 2019/09/25 14:31:51 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "./libft/libft.h"

typedef struct s_ant
{
	int id;
	int pos_id;
	char *pos;
	char *pos_name;
	char *path;
}				t_ant;

typedef struct s_room
{
	int id;
	char *r_id;
	char *name;
	char *pos;
	int x;
	int y;
	int v;
	int n_links;
	int *links;
	int	n_ants;
}				t_room;

typedef	struct s_farm
{
	int	n_ants;
	t_ant *ants;
	int n_rooms;
	int n_links;
	t_room *rooms;
	char *f_rooms;
	char *f_links;
	int start;
	int end;
	char *f_farm;
	int n_paths;
	char **paths;
	char *f_paths;
} 				t_farm;

int build_rooms(t_farm *farm);
int check_end(t_farm *farm);
int check_start(t_farm *farm);
int check_start_end(t_farm *farm);
int command(char *line);
int	create_ants(char *line, t_farm *farm);
int end_command(char *line);
void error(void);
void exit_farm(t_farm *farm);
void free_arr(char **arr);
void free_farm(t_farm *farm);
int ignore_command(char *line);
void initialise_ants(t_farm *farm);
void initialise_every_room(t_farm *farm);
void initialise_farm(t_farm *farm);
void initialise_room(int j, char *room, t_farm *farm);
void initialise_start_end(char *command, char *room, t_farm *farm, int j);
int start_command(char *line);
int validate_farm(t_farm *farm);
int validate_room(char *line);
int	save_rooms(char *line, char **rooms, t_farm *farm);
int	save_links(char *line, char **links, t_farm *farm);
int	read_farm(t_farm *farm);
void print_rooms(t_farm *farm);
void print_ants(t_farm *farm);
int number_of_ants(int j, t_farm *farm);
int is_link(char *line);
int get_link(int room, char *link, t_farm *farm);
void assign_links_to_room(int room, int n_links, t_farm *farm);
int count_links(int i, t_farm *farm);
int assign_links(t_farm *farm);
#endif