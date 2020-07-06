#include "lem_in.h"

int		save_rooms(char *line, char **rooms, t_farm *farm)
{
	char	*tmp;

	if (validate_room(line) ==  1)
	{
		if (*rooms == NULL)
			*rooms = ft_strnew(0);
		tmp = *rooms;
		*rooms = ft_strjoin(*rooms, line);
		free(tmp);
		tmp = *rooms;
		*rooms = ft_strjoin(*rooms, "\n");
		farm->n_rooms++;
		free(tmp);
		return (1);
	}
	free(*rooms);
	free(line);
	return (0);
}