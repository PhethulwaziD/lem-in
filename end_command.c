#include "lem_in.h"

int end_command(char *line)
{
	if (ft_strcmp(line, "##end") == 0)
		return (1);
	return (0);
}