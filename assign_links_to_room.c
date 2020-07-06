#include "lem_in.h"

void assign_links_to_room(int room, int n_links, t_farm *farm)
{
	int j;
	int i;
	char **links;
	int *arr;

	j = 0;
	i = 0;
	links = ft_strsplit(farm->f_links, '\n');
	if (links)
	{
		arr = (int*)malloc(sizeof(int) * n_links);
		while(links[j])
		{
			if (ft_strstr(links[j], farm->rooms[room].name))
			{
				arr[i] = get_link(room, links[j], farm);
				i++;
			}
			j++;
		}
		farm->rooms[room].links = arr;
	}
	free_arr(links);	
}