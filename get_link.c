#include "lem_in.h"

int get_link(int room, char *link, t_farm *farm)
{
	int i;
	char *name;
	char **l_rooms;
	
	name = NULL;
	i = 0;
	l_rooms = ft_strsplit(link,'-');
	if (ft_strcmp(farm->rooms[room].name, l_rooms[0]) == 0)
		name = l_rooms[1];
	else if(ft_strcmp(farm->rooms[room].name, l_rooms[1]) == 0)
		name = l_rooms[0];
	if(name)
	{
		while (i < farm->n_rooms)
		{
			if (ft_strcmp(farm->rooms[i].name, name) == 0)
			{
				free_arr(l_rooms);
				return (farm->rooms[i].id);
			}
			i++;
		}
	}
	free_arr(l_rooms);
	return (-1);
}