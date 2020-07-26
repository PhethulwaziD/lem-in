#include "lem_in.h"

static int link_not_marked(int l_room, t_farm *farm)
{
	if ((l_room = farm->rooms[l_room].v) == 0)
		return (1);
	return (0);
}

static int rooms_not_marked(int room, t_farm *farm)
{
	int i;
	int l_room;

	i = 0;
	while (i < farm->rooms[room].n_links)
	{
		l_room = farm->rooms[room].links[i];
		if (farm->rooms[l_room].v == 0)
			return (0);
		i++;
	}
	return (1);
}

static void mark_room_links(int room, t_farm *farm)
{
	int i;
	int l_room;

	i = 0;
	while (i < farm->rooms[room].n_links)
	{
		l_room = farm->rooms[room].links[i];
		if (link_not_marked(l_room, farm) == 1)
			farm->rooms[l_room].v = farm->rooms[room].v + 1;
		i++;
	}
}

static int create_paths(t_farm *farm)
{
	int room;
	int i;

	i = 0;
	room = farm->start;
	farm->rooms[room].v = 1;
	while(i < farm->n_rooms)
	{
		if (farm->rooms[i].v > 0)
		{
			if (farm->rooms[i].n_links > 0)
			{
				if (rooms_not_marked(i, farm) == 0)
				{
					mark_room_links(i, farm);
					i = 0;
				}
			}
		}
		i++;
	}
	if (farm->rooms[farm->end].v > 0)
		return (1);
	return (0);
}

static int start_end_links_exist(t_farm *farm)
{
	if (farm->rooms[farm->start].n_links <= 0)
		return (0);
	else if (farm->rooms[farm->end].n_links <= 0)
		return (0);
	return (1);
}

static int find_paths(t_farm *farm)
{
	if (start_end_links_exist(farm) == 1)
	{
		if (create_paths(farm) == 1)
			return (1);
	}	
	return (0);
}

static void append_path(t_farm *farm, int room)
{
	char *tmp;

	tmp = NULL;
	if (farm->f_paths == NULL)
	{
		farm->f_paths = ft_strnew(0);
		append_path(farm, farm->end);
	}
	tmp = farm->f_paths;
	farm->f_paths = ft_strjoin(farm->rooms[room].r_id, farm->f_paths);
	free(tmp);
	tmp = farm->f_paths;
	farm->f_paths = ft_strjoin(" ",farm->f_paths);
	free(tmp);
}

static void get_paths(t_farm *farm)
{
	int i;
	int j;

	i = farm->rooms[farm->end].v;
	if (i > farm->rooms[farm->start].v)
	{
		while (i > farm->rooms[farm->start].v)
		{
			j = 0;
			while (j < farm->n_rooms)
			{
				if (farm->rooms[j].v == (i - 1))
				{
					append_path(farm, j);
					if (farm->rooms[j].id != farm->rooms[farm->start].id)
						farm->rooms[j].v = 0;
					i--;
					break ;
				}
				j++;
			}
		}
		farm->n_paths++;
	}
}

static void assign_paths(t_farm *farm)
{
	int i;
	char *tmp;

	i = 0;
	tmp = farm->f_paths;
	farm->f_paths = ft_strtrim(farm->f_paths);
	free(tmp);
	while (i < farm->n_ants)
	{
		farm->ants[i].path = farm->f_paths;
		i++;
	}
}

static void print_move(t_farm *farm, int ant, int next)
{
	ft_putstr("L");
	ft_putnbr(farm->ants[ant].id);
	ft_putstr("-");
	ft_putstr(farm->rooms[next].name);
	ft_putendl("");

}

static void move_ant(t_farm *farm, int ant)
{
	char **path;
	int i;
	int curr;
	int next;

	path = ft_strsplit(farm->f_paths, ' ');
	i = 0;
	while (path[i] && farm->ants[ant].pos_id != farm->rooms[farm->end].id)
	{
		curr = ft_atoi(path[i]);
		i++;
		if (path[i] && ft_isint(path[i]))
			next = ft_atoi(path[i]);
		if (farm->ants[ant].pos_id != next)
		{
			farm->rooms[next].n_ants++;
			farm->rooms[curr].n_ants--;
			farm->ants[ant].pos_id =  next;
			print_move(farm, ant, next);
		}
	}
	free_arr(path);
}

static void execute_paths(t_farm *farm)
{
	int i;

	i = 0;
	while (i < farm->n_ants)
	{
		move_ant(farm, i);
		i++;
	}
}

static void next(t_farm *farm)
{
	if (assign_links(farm) == 1)
	{
		if (find_paths(farm) == 1)
		{
			get_paths(farm);
			if (farm->n_paths > 0)
			{
				assign_paths(farm);
				ft_putstr(farm->f_farm);
				ft_putendl("");
				execute_paths(farm);
			}
			else
				exit_farm(farm);
		}
		else
	 		exit_farm(farm);
	}
	else
	 	exit_farm(farm);
}

int			main(void)
{
	t_farm  farm;

	initialise_farm(&farm);
	if (read_farm(&farm) == 1)
	{
		if (validate_farm(&farm) == 1)
		{
			if (build_rooms(&farm) == 1)
			{
			 	next(&farm);
			}
			else
			 	exit_farm(&farm);
		}
		else
				exit_farm(&farm);
	}
	else
		exit_farm(&farm);
	free_farm(&farm);
	return (0);
}
