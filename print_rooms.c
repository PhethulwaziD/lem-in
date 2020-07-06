#include "lem_in.h"

static void print_links(int room, t_farm *farm)
{
	int i;

	i = 0;
	ft_putstr("links: ");
	while (i < farm->rooms[room].n_links)
	{
		ft_putnbr(farm->rooms[room].links[i]);
		ft_putstr(" ");
		i++;
	}
	ft_putendl(" ");
}

void print_rooms(t_farm *farm)
{
	int i;

	i = 0;
	while (i < farm->n_rooms)
	{
		ft_putstr("r_id:");
		ft_putendl(farm->rooms[i].r_id);
		ft_putstr("id:");
		ft_putnbr(farm->rooms[i].id);
		ft_putendl("");
		ft_putstr("name:");
		ft_putendl(farm->rooms[i].name);
		ft_putstr("Position:");
		ft_putendl(farm->rooms[i].pos);
		ft_putstr("X:");
		ft_putnbr(farm->rooms[i].x);
		ft_putendl("");
		ft_putstr("Y:");
		ft_putnbr(farm->rooms[i].y);
		ft_putendl("");
		ft_putstr("V:");
		ft_putnbr(farm->rooms[i].v);
		ft_putendl("");
		ft_putstr("Ants:");
		ft_putnbr(farm->rooms[i].n_ants);
		ft_putendl("");
		ft_putstr("No.Links:");
		ft_putnbr(farm->rooms[i].n_links);
		ft_putendl("");
		print_links(i, farm);
		ft_putendl(" ");
		i++;
	}
}