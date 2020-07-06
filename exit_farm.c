#include "lem_in.h"

void exit_farm(t_farm *farm)
{
	free_farm(farm);
	error();
}