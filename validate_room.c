#include "lem_in.h"

int validate_room(char *line)
{
	char **details;
	char *tmp;

	tmp = ft_strtrim(line);
	if (start_command(tmp) == 1 || end_command(tmp) == 1)
	{
		free(tmp);
		return (1);
	}
	else if (command(tmp) == 0)
	{
		details = ft_strsplit(tmp, ' ');
		if (details[0] != NULL && details[1] != NULL && details[2] != NULL)
		{
			if(ft_isint(details[1]) == 1 && ft_isint(details[2]) == 1)
			{
				free(tmp);
				free_arr(details);
				return (1);
			}
		}
		free_arr(details);
	}
	return (0); 
}