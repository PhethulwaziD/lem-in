#include "lem_in.h"

int command(char *line)
{
	if (start_command(line) == 1 || end_command(line) == 1)
		return (1);
	else if (ignore_command(line) == 1)
		return (1);
	return (0);
}