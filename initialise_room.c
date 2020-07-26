#include "lem_in.h"

void initialise_room(int j, char *room, t_farm *farm)
{
	char **r_info;
	if (farm->rooms)
	{
		if (farm->rooms[j].pos == NULL)
			farm->rooms[j].pos = ft_strdup("room");
		r_info = ft_strsplit(room, ' ');
		farm->rooms[j].r_id = ft_itoa(j);
		farm->rooms[j].id = j;
		farm->rooms[j].name = ft_strdup(r_info[0]);
		farm->rooms[j].x = ft_atoi(r_info[1]);
		farm->rooms[j].y = ft_atoi(r_info[2]);
		farm->rooms[j].n_ants = number_of_ants(j, farm);
		free_arr(r_info);
	}
}