/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravaono <dravaono@student42nice.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:42:09 by dravaono          #+#    #+#             */
/*   Updated: 2023/07/02 16:31:33 by dravaono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**cpy_path(t_map *mappy)
{
	int		j;
	char	**mappath;
	int		i;

	mappath = malloc(sizeof(char *) * (mappy->linemap + 1));
	j = -1;
	while (mappy->mapgnl[++j])
	{
		i = -1;
		mappath[j] = malloc(sizeof(char *) * (mappy->lenline + 1));
		while (mappy->mapgnl[j][++i])
			mappath[j][i] = mappy->mapgnl[j][i];
	}
	mappath[j] = 0;
	return (mappath);
}

void	change_s(char **mappath, int y, int x)
{
	if (mappath[y][x + 1] != '1' && mappath[y][x + 1] != 'X')
		mappath[y][x + 1] = 'V';
	if (mappath[y][x - 1] != '1' && mappath[y][x - 1] != 'X')
		mappath[y][x - 1] = 'V';
	if (mappath[y + 1][x] != '1' && mappath[y + 1][x] != 'X')
		mappath[y + 1][x] = 'V';
	if (mappath[y - 1][x] != '1' && mappath[y - 1][x] != 'X')
		mappath[y - 1][x] = 'V';
}

void	validpath(char **mappath)
{
	int		y;
	int		x;

	y = -1;
	while (mappath[++y])
	{
		x = -1;
		while (mappath[y][++x])
		{
			if (mappath[y][x] == 'C' || mappath[y][x] == 'E')
			{
				ft_error(6);
				free(mappath[y]);
			}
		}
	}
	free(mappath);
}

void	search_path(t_map *mappy)
{
	int		y;
	int		x;
	char	**mappath;

	y = 0;
	mappath = cpy_path(mappy);
	while (mappath[++y])
	{
		x = 0;
		while (mappath[y][++x])
		{
			if (mappath[y][x] == 'P' || mappath[y][x] == 'V')
			{
				mappath[y][x] = 'X';
				change_s(mappath, y, x);
				y = 0;
			}
		}
	}
	validpath(mappath);
}
