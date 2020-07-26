#include "lem_in.h"

int validate_room(char *line)
{
	char **details;

	if (start_command(line) == 1 || end_command(line) == 1 || ignore_command(line) == 1)
		return (1);
	else if (command(line) == 0)
	{
		details = ft_strsplit(line, ' ');
		if (details[0] != NULL && details[1] != NULL && details[2] != NULL)
		{
			if(ft_isint(details[1]) == 1 && ft_isint(details[2]) == 1)
			{
				free_arr(details);
				return (1);
			}
		}
		free_arr(details);
	}
	return (0); 
}