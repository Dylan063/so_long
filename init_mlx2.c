/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravaono <dravaono@student42nice.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:52:32 by dravaono          #+#    #+#             */
/*   Updated: 2023/07/04 19:57:25 by dravaono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_loop(t_game *game)
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
	static int	j;

	if (!j)
		j = 0;
	if (game->map[y][x] == 'E')
		collect(game);
	else if (game->map[y][x] != '1')
	{
		j++;
		ft_printf("%d\n", j);
		game->map[y][x] = 'P';
		game->map[game->playery][game->playerx] = '0';
	}
}

int	key_press(int keycode, t_game *game)
{
	get_player(game);
	if (keycode == 53)
		exit(0);
	if (keycode == 13)
		move_player(game, game->playery - 1, game->playerx);
	if (keycode == 1)
		move_player(game, game->playery + 1, game->playerx);
	if (keycode == 0)
		move_player(game, game->playery, game->playerx - 1);
	if (keycode == 2)
		move_player(game, game->playery, game->playerx + 1);
	return (0);
}
