#include "lem_in.h"

static int no_spaces(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			return (0);
		i++;
	}
	return (1);
}

int		create_ants(char *line, t_farm *farm)
{
	if (no_spaces(line) == 1)
	{
		if ((ft_isint(line) == 1) )
		{
			farm->n_ants = ft_atoi(line);
			if (farm->n_ants > 0) 
			{
				initialise_ants(farm);
				return (1);
			}
		}
	}
	free(line);
	free_farm(farm);
	return (0);
}