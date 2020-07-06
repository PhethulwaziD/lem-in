#include "lem_in.h"

void initialise_farm(t_farm *farm)
{
	farm->n_ants = 0;
	farm->n_rooms = 0;
	farm->n_links = 0;
	farm->end = -1;
	farm->start = -1;
	farm->f_rooms = NULL;
	farm->f_links = NULL;
	farm->ants = NULL;
	farm->rooms = NULL;
	farm->paths = NULL;
	farm->f_paths = NULL;
	farm->n_paths = 0;
}