#include "lem_in.h"

void initialise_ants(t_farm *farm)
{
	int 	i;

	i = 0;
	t_ant *array = malloc(farm->n_ants * sizeof(t_ant));
	while (i < farm->n_ants)
	{
		array[i].id = i + 1;
		array[i].pos = ft_strdup("start");
		array[i].pos_id = 0;
		array[i].path = NULL;
		array[i].pos_name = NULL;
		i++;
	}
	farm->ants = array;
}