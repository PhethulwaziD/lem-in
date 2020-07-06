#include "lem_in.h"

int check_start(t_farm *farm)
{
	if (ft_strstr(farm->f_rooms, "##start") == NULL)
		return (0);
	farm->n_rooms--;
	return (1);
}
