#include "lem_in.h"

int empty_line(char *line)
{
	char *tmp;

	tmp = ft_strtrim(line);
	if (line)
	{
		if (ft_strlen(tmp) == 0)
		{
			free(tmp);
			return (1);
		}
	}
	free(tmp);
	return (0);
}

static void save_farm(t_farm *farm, char *line)
{
	char *tmp;

	tmp = NULL;
	if (farm->f_farm == NULL)
		farm->f_farm = ft_strnew(0);
	tmp = farm->f_farm;
	farm->f_farm = ft_strjoin(farm->f_farm, line);
	free(tmp);
	tmp = farm->f_farm;
	farm->f_farm = ft_strjoin(farm->f_farm, "\n");
	free(tmp);
}

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
		if (empty_line(line) == 1)
		{
			free(line);
			return (0);
		}
		if (i == 0 && command(line) == 0 && is_link(line) == 0)
			if (create_ants(line, farm) == 0)
				return (0);
		if (i > 0 && farm->n_ants > 0 && is_link(line) == 0 && ignore_command(line) == 0)
			if (save_rooms(line, &rooms, farm) == 0)
				return (0);
		if (i > 0 && is_link(line) == 1)
			if (save_links(line, &links, farm) == 0)
				return (0);
		save_farm(farm, line);
		free(line);
		i++;
	}
	farm->f_rooms = rooms;
	farm->f_links = links;
	return (1);
}
