#include "lem_in.h"

int		create_ants(char *line, t_farm *farm)
{
	char	*val;

	val = ft_strtrim(line);
	if ((ft_isint(val) == 1))
	{
		farm->n_ants = ft_atoi(line);
		if (farm->n_ants > 0) 
		{
			free(val);
			initialise_ants(farm);
			return (1);
		}
	}
	free(line);
	free(val);
	free_farm(farm);
	return (0);
}
