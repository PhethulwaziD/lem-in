#include "lem_in.h"

int is_link(char *line)
{
	if (ft_strchr(line, '-'))
		return (1);
	return (0);
}