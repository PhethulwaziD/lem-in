#include "lem_in.h"

int start_command(char *line)
{
	if (ft_strcmp(line, "##start") != 0)
		return (0);
	return (1);
}