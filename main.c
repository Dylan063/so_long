/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravaono <dravaono@student42nice.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:08:53 by dravaono          #+#    #+#             */
/*   Updated: 2023/06/22 15:47:52 by dravaono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	mappy;
	t_game	game;
	int		i;
	
	if (ac != 2)
		return (1);
	i = 0;
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4,".ber", 48))
		ft_error(5);
	parsing(&mappy, av[1]);
	game.map = mappy.mapgnl;
	game.width = mappy.lenline;
	game.height = mappy.linemap;
	init_mlx(&game);
	system("leaks so_long");
	return (0);
}
