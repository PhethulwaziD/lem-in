#include "lem_in.h"


static void free_ants(t_farm *farm)
{
	int i;

	i = 0;
	if (farm->n_ants > 0)
	{
		while (i < farm->n_ants)
		{
			if (farm->ants[i].pos)
				free(farm->ants[i].pos);
			i++;
		}
		free(farm->ants);
	}
}

static void free_rooms(t_farm *farm)
{
	int j;

	j = 0;
	if (farm->rooms)
	{
	  	while (j < farm->n_rooms)
	  	{
			if (farm->rooms[j].pos != NULL || farm->rooms[j].name != NULL)
			{
				if (farm->rooms[j].r_id)
					free(farm->rooms[j].r_id);
				if (farm->rooms[j].pos)
					free(farm->rooms[j].pos);
				if (farm->rooms[j].name)
					free(farm->rooms[j].name);
				if(farm->rooms[j].links)
					free(farm->rooms[j].links);
			}
	 		j++;
	 	}
	  	free(farm->rooms);
	}
}

void free_farm(t_farm *farm)
{
	
	free_ants(farm);
	if(farm->f_rooms != NULL)
	 	free(farm->f_rooms);
	if(farm->f_links != NULL)
	 	free(farm->f_links);
	if (farm->f_paths != NULL)
	 	free(farm->f_paths);
	free_rooms(farm);
}