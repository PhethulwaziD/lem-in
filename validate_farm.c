#include "lem_in.h"

int validate_farm(t_farm *farm)
{
	if (farm->n_rooms <= 1 || farm->n_links == 0 || farm->n_ants == 0)
		return (0);
	if (check_start_end(farm) == 0)
		return (0);
	return (1);
}