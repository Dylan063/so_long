/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravaono <dravaono@student42nice.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:08:53 by dravaono          #+#    #+#             */
/*   Updated: 2023/07/02 17:09:30 by dravaono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fd_test(char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error(4);
	else
		close(fd);
}

void	number_move(t_game *game)
{
	write(1, "move", 4);
	ft_putnbr_fd(game->move, 1);
}

void	parsing(t_map *mappy, char *av)
{
	fd_test(av);
	sizemap(mappy, av);
	cpymap(mappy, av);
	samelen(mappy);
	wall(mappy);
	allneed(mappy);
	search_path(mappy);
}

int	main(int ac, char **av)
{
	t_map	mappy;
	t_game	game;
	int		i;

	if (ac != 2)
		return (1);
	i = 0;
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 48))
		ft_error(5);
	parsing(&mappy, av[1]);
	game.map = mappy.mapgnl;
	game.width = mappy.lenline;
	game.height = mappy.linemap;
	init_mlx(&game);
	system("leaks so_long");
	return (0);
}
