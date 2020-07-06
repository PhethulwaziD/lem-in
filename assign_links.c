#include "lem_in.h"

int assign_links(t_farm *farm)
{
	int 	i;
	int 	n;
	
	i = 0;
	if (farm->f_links)
	{
		while (i < farm->n_rooms)
		{
			if ((n = count_links(i, farm)) > 0)
				assign_links_to_room(i, n, farm);
			i++;
		}
		return (1);
	}
	return (0);
}
