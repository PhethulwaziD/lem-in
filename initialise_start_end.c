#include "lem_in.h"

void initialise_start_end(char *command, char *room, t_farm *farm, int j)
{
	if (ft_strcmp(command, "##start") == 0)
	{
		farm->start = j;
		farm->rooms[j].pos = ft_strdup("start");
	}
	else if (ft_strcmp(command, "##end") == 0)
	{
		farm->end = j;
		farm->rooms[j].pos = ft_strdup("end");
	}
	initialise_room(j, room, farm);
}
