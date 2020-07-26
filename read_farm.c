#include "lem_in.h"

int empty_line(char *line)
{

	if (line)
	{
		if (line[0] == '\n' || line[0] == '\t' || line[0] == ' ')
			return (0);
	}
	return (1);
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
static int n_spaces(char *line)
{
	int i;
	int spaces;

	i = 0;
	spaces = 0;
	if (line)
	{
		while(line[i])
		{
			if (line[i] == ' ')
				spaces++;
			i++;
		}
	}
	return (spaces);
}
static int is_room(char *line)
{

	if (start_command(line) == 1 || end_command(line) == 1 || ignore_command(line) == 1)
	{
		if (n_spaces(line) == 0)
			return (1);
	}
	else if (n_spaces(line) == 2)
		return (1);
	return (0);
}

static int invalid_line(char *line, t_farm *farm)
{
	if (is_room(line) == 0)
	{
		if (n_spaces(line) > 0)
			return (1);
		else if (is_link(line) == 0)
		{
			if (ft_isint(line) == 1 && farm->n_ants > 0)
				return (1);
			else if (ft_isint(line) == 0)
				return (1);
		}
	}
	return (0);
}

static int according(t_farm *farm)
{
	char **arr;
	int i;

	i = 0;
	arr = ft_strsplit(farm->f_farm, '\n');
	while (arr[i])
	{
		if ((n_spaces(arr[i]) == 2 ||  end_command(arr[i]) == 1 || start_command(arr[i])== 1))
		{
			if ((i - 1) > 0)
			{
				if (is_link(arr[i - 1]))
				{
					free_arr(arr); 
					return (0);
				}
			}
		}
		else if (is_link(arr[i]))
		{
			if (arr[i + 1])
			{
				if (arr[i + 1] && (n_spaces(arr[i + 1]) == 2 ||  end_command(arr[i + 1]) == 1
				|| start_command(arr[i + 1])== 1))
				{
					free_arr(arr);
					return (0);
				}
			}
		}
		i++;
	}
	free_arr(arr);
	return (1);
}

static int sequence(t_farm *farm)
{
	if (farm->n_ants == 0 && farm->n_rooms > 0)
		return (0);
	else if (farm->n_ants == 0 && farm->n_links > 0)
		return (0);
	else if (farm->n_links > 0 && farm->n_rooms == 0)
		return (0);
	return (1);
}

int	read_farm(t_farm *farm)
{
	char	*line;
	
	while (get_next_line(0, &line) > 0)
	{
		if (empty_line(line) == 0)
		{
			free(line);
			return (0);
		}
		if (invalid_line(line, farm) == 1 || sequence(farm) == 0)
		{
			free(line);
			return (0);	
		}
		if (farm->n_ants == 0 && command(line) == 0 && is_link(line) == 0 && n_spaces(line) == 0)
			if (create_ants(line, farm) == 0)
				return (0);
		if (start_command(line) == 1 || end_command(line) == 1 || n_spaces(line) == 2)
		{
		 	if (save_rooms(line, farm) == 0)
		 		return (0);
		}
		if (is_link(line) == 1 && n_spaces(line) == 0)
			if (save_links(line, farm) == 0)
				return (0);
		save_farm(farm, line);
		if (line != NULL)
			free(line);
	}
	if (according(farm) == 0)
		return (0);
	return (1);
}
