/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravaono <dravaono@student42nice.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:08:53 by dravaono          #+#    #+#             */
/*   Updated: 2023/07/06 14:37:06 by dravaono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fd_test(char *av)
{
	if (open(av, O_DIRECTORY) != -1)
		ft_error(0);
	if (open(av, O_RDONLY) == -1)
		ft_error(4);
}

void	parsing(t_map *mappy, char *av)
{
	fd_test(av);
	sizemap(mappy, av);
	cpymap(mappy, av);
	samelen(mappy);
	wall(mappy);
	allneed(mappy);
	caractmap(mappy);
	search_path(mappy);
	search_path2(mappy);
}

int	main(int ac, char **av)
{
	t_map	mappy;
	t_game	game;

	if (ac != 2)
		return (1);
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 48))
		ft_error(5);
	parsing(&mappy, av[1]);
	game.map = mappy.mapgnl;
	game.width = mappy.lenline;
	game.height = mappy.linemap;
	init_mlx(&game);
	return (0);
}

void	allneed(t_map *mappy)
{
	cneed(mappy);
	pneed(mappy);
	eneed(mappy);
}

void	caractmap(t_map *mappy)
{
	int	y;
	int	x;

	y = -1;
	while (mappy->mapgnl[++y])
	{
		x = -1;
		while (mappy->mapgnl[y][++x] != '\n')
		{
			if ((mappy->mapgnl[y][x] != '1') && (mappy->mapgnl[y][x] != '0')
				&& (mappy->mapgnl[y][x] != 'E') && (mappy->mapgnl[y][x] != 'C')
				&& (mappy->mapgnl[y][x] != 'P'))
				ft_error(0);
		}
	}
}
