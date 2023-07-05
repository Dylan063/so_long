/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravaono <dravaono@student42nice.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:21:32 by dravaono          #+#    #+#             */
/*   Updated: 2023/07/03 19:21:09 by dravaono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_image(t_game *game, char *path)
{
	int		a;
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, path, &a, &a);
	if (!img)
		ft_error(7);
	return (img);
}

void	init_img(t_game *game)
{
	game->img.floor = get_image(game, "./xpm/floor-green.xpm");
	game->img.mario = get_image(game, "./xpm/mario.xpm");
	game->img.wall = get_image(game, "./xpm/wall1.xpm");
	game->img.collec = get_image(game, "./xpm/collec.xpm");
	game->img.exit = get_image(game, "./xpm/exit.xpm");
}

void	print_img(t_game *game, void *img, int x, int y)
{
	if (!img)
		ft_error(7);
	mlx_put_image_to_window(game->mlx, game->win, img, x * 64, y * 64);
}

int	ft_exit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (game->width - 1) * 64,
			game->height * 64, "so_long");
	if (!game->win)
		ft_error(8);
	init_img(game);
	mlx_loop_hook(game->mlx, &game_loop, game);
	mlx_hook(game->win, 2, 0, &key_press, game);
	mlx_hook(game->win, 17, 0, &ft_exit, game);
	mlx_loop(game->mlx);
}
