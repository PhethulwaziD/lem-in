#include "lem_in.h"

int check_start_end(t_farm *farm)
{
	if (check_start(farm) == 0)
		return (0);
	if (check_end(farm) == 0)
		return (0);
	return (1);
}