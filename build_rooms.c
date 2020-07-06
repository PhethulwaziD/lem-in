#include "lem_in.h"

int build_rooms(t_farm *farm)
{
	char **rooms;
	int 	i;
	int 	j;
	char 	*line;

	i = 0;
	j = 0;
	rooms = ft_strsplit(farm->f_rooms, '\n');
	t_room *array = malloc((farm->n_rooms) * sizeof(t_room));
	if (rooms)	
	{	
		farm->rooms = array;
		initialise_every_room(farm);
		while (rooms[i])
		{
			line = rooms[i];
			if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##end") == 0)
			{
				i++;
				if (rooms[i])
			 		initialise_start_end(line, rooms[i], farm, j);
			}
			else if (ft_strcmp(rooms[i], "##start") != 0 || ft_strcmp(rooms[i], "##end") != 0)
			 	initialise_room(j, rooms[i], farm);
			i++;
			j++;
		}
		free_arr(rooms);
		return (1);
	}
	return (0);
}