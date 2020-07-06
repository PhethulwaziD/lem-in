#include "lem_in.h"

int		save_links(char *line, char **links, t_farm *farm)
{
	char	*tmp;

	if (is_link(line) ==  1)
	{
		if (*links == NULL)
			*links = ft_strnew(0);
		tmp = *links;
		*links = ft_strjoin(*links, line);
		free(tmp);
		tmp = *links;
		*links = ft_strjoin(*links, "\n");
		free(tmp);
		farm->n_links++;
		return (1);
	}
	free(*links);
	free(line);
	return (0);
}