#include "lem_in.h"

void print_ants(t_farm *farm)
{
	int i;

	i = 0;
	while (i < farm->n_ants)
	{
		ft_putstr("id:");
		ft_putnbr(farm->ants[i].id);
		ft_putendl("");
		ft_putstr("position:");
		ft_putstr(farm->ants[i].pos);
		ft_putendl("");
		ft_putstr("path:");
		ft_putstr(farm->ants[i].path);
		ft_putendl("");
		ft_putstr("pos_id:");
		ft_putnbr(farm->ants[i].pos_id);
		ft_putendl("");
		ft_putstr("pos_name:");
		ft_putstr(farm->ants[i].pos_name);
		ft_putendl("");
		ft_putendl("");
		i++;
	}
}