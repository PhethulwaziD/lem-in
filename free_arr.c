#include "lem_in.h"

void free_arr(char **arr)
{
	int 	i;

	i = 0;
	if (arr)
	{
		while(arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}