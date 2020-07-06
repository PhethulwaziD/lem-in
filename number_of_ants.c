#include "lem_in.h"

int number_of_ants(int j, t_farm *farm)
{
	if (ft_strcmp(farm->rooms[j].pos, "start") == 0)
		return (farm->n_ants);
	return (0);
}