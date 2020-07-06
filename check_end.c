#include "lem_in.h"

int check_end(t_farm *farm)
{
	if (ft_strstr(farm->f_rooms, "##end") == NULL)
		return (0);
	farm->n_rooms--;
	return (1);
}
