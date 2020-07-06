#include "lem_in.h"

void initialise_every_room(t_farm *farm)
{
	int j;

	j = 0;
	if (farm->rooms)
	{
		while (j < farm->n_rooms)
		{
			farm->rooms[j].r_id = NULL;
			farm->rooms[j].id = -1;
			farm->rooms[j].pos = NULL;
			farm->rooms[j].name = NULL;
			farm->rooms[j].links = NULL;
			farm->rooms[j].y = -1;
			farm->rooms[j].y = -1;
			farm->rooms[j].v = 0;
			farm->rooms[j].n_ants = 0;
			farm->rooms[j].n_links = 0;
			j++;
		}
	}
}
