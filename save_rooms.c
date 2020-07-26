#include "lem_in.h"

int		save_rooms(char *line, t_farm *farm)
{
	char	*tmp;

	if (validate_room(line) ==  1)
	{
		if (farm->f_rooms == NULL)
			farm->f_rooms = ft_strnew(0);
		tmp = farm->f_rooms;
		farm->f_rooms = ft_strjoin(farm->f_rooms, line);
		free(tmp);
		tmp = farm->f_rooms;
		farm->f_rooms = ft_strjoin(farm->f_rooms, "\n");
		farm->n_rooms++;
		free(tmp);
		return (1);
	}
	free(line);
	return (0);
}