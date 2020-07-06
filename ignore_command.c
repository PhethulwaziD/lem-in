#include "lem_in.h"

int ignore_command(char *line)
{
	if (ft_strchr(line, '#'))
	{
		if(start_command(line) == 0 && end_command(line) == 0)
			return (1);
	}
	return (0);
}