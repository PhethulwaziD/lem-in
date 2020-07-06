#include "lem_in.h"

int	read_farm(t_farm *farm)
{
	char	*line;
	int		i;
	char	*rooms;
	char	*links;
	
	rooms = NULL;
	links = NULL;
	i = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (i == 0 && command(line) == 0 && is_link(line) == 0)
			if (create_ants(line, farm) == 0)
				return (0);
		if (i > 0 && farm->n_ants > 0 && is_link(line) == 0 && ignore_command(line) == 0)
			if (save_rooms(line, &rooms, farm) == 0)
				return (0);
		if (i > 0 && is_link(line) == 1)
			if (save_links(line, &links, farm) == 0)
				return (0);
		ft_putendl(line);
		free(line);
		i++;
	}
	ft_putendl("");
	farm->f_rooms = rooms;
	farm->f_links = links;
	return (1);
}