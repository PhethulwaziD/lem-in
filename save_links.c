#include "lem_in.h"

int		save_links(char *line, t_farm *farm)
{
	char	*tmp;

	if (is_link(line) ==  1)
	{
		if (farm->f_links == NULL)
			farm->f_links = ft_strnew(0);
		tmp = farm->f_links;
		farm->f_links = ft_strjoin(farm->f_links, line);
		free(tmp);
		tmp = farm->f_links;
		farm->f_links = ft_strjoin(farm->f_links, "\n");
		free(tmp);
		farm->n_links++;
		return (1);
	}
	free(line);
	return (0);
}