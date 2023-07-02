/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravaono <dravaono@student42nice.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:21:32 by dravaono          #+#    #+#             */
/*   Updated: 2023/07/02 16:25:32 by dravaono         ###   ########.fr       */
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

/*int	game_loop(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] != '\n')
		{
			print_img(game, game->img.floor, x, y);
			if (game->map[y][x] == 'P')
				print_img(game, game->img.mario, x, y);
			if (game->map[y][x] == '1')
				print_img(game, game->img.wall, x, y);
			if (game->map[y][x] == 'C')
				print_img(game, game->img.collec, x, y);
			if (game->map[y][x] == 'E')
				print_img(game, game->img.exit, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

void	get_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[++y])
	{
		x = 0;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'P')
			{
				game->playerx = x;
				game->playery = y;
			}
		}
	}
}

void	collect(t_game *game)
{
	int	x;
	int	y;
	int	j;

	j = 0;
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'C')
				j++;
		}
	}
	if (j == 0)
		exit(0);
}

void	move_player(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'E')
		collect(game);
	else if (game->map[y][x] != '1')
	{
		game->map[y][x] = 'P';
		game->map[game->playery][game->playerx] = '0';
	}
}

int	key_press(int keycode, t_game *game)
{
	get_player(game);
	if (keycode == 53)
		exit(0);
	else if (keycode == 13)
		move_player(game, game->playery - 1, game->playerx);
	else if (keycode == 1)
		move_player(game, game->playery + 1, game->playerx);
	else if (keycode == 0)
		move_player(game, game->playery, game->playerx - 1);
	else if (keycode == 2)
		move_player(game, game->playery, game->playerx + 1);
	return (0);
}*/

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
