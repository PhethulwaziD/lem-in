#include "lem_in.h"

int count_links(int i, t_farm *farm)
{
	int j;
	char **links;
	int n;

	n = 0;
	j = 0;
	links = ft_strsplit(farm->f_links, '\n');
	if (links)
	{
		while(links[j])
		{
			if (ft_strstr(links[j], farm->rooms[i].name))
				n++;
			j++;
		}
		farm->rooms[i].n_links = n;
		free_arr(links);
		return (n);
	}
	free_arr(links);
	return (0);
}