/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravaono <dravaono@student42nice.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:38:00 by dravaono          #+#    #+#             */
/*   Updated: 2023/06/24 15:24:33 by dravaono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	samelen(t_map *mappy)
{
	int	y;
	
	mappy->lenline = ft_strlen(mappy->mapgnl[0]);
	y = 0;
	while (mappy->mapgnl[++y])
		if (ft_strlen(mappy->mapgnl[y]) != mappy->lenline)
			ft_error(1);
}


void	wall(t_map *mappy)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while(mappy->mapgnl[y])
	{
		while ((mappy->mapgnl[0][x] && mappy->mapgnl[0][x] != '\n') 
		|| (mappy->mapgnl[mappy->linemap -1][x] && mappy->mapgnl[mappy->linemap -1][x] != '\n' ))
		{
			if (mappy->mapgnl[0][x] != '1' || mappy->mapgnl[mappy->linemap -1][x] != '1')
				ft_error(2);
			else
				x++;
		}
		if (mappy->mapgnl[y][0] != '1' || mappy->mapgnl[y][mappy->lenline - 2] != '1')
			ft_error(2); 
		else
			y++;
	}
}

void	Cneed(t_map *mappy)
{
	int	y;
	int	x;

	y = -1;
	x = 1;
	while(mappy->mapgnl[++y])
		if ((ft_strchr(mappy->mapgnl[y], 'C')))
			x = 2;
	if (x == 1)
		ft_error(3);		
}
void	Pneed(t_map *mappy)
{
	int	y;
	int	x;
	int	j;

	y = -1;
	j = 1;
	while(mappy->mapgnl[++y])
	{
		x = -1;
		while(mappy->mapgnl[y][++x])
		{
			if (mappy->mapgnl[y][x] == 'P')
			{
				j++;
			}
		}
	}
	if (j != 2)
		ft_error(3);	
}
void	Eneed(t_map *mappy)
{
	int	y;
	int	x;
	int	j;

	y = -1;
	j = 1;
	while(mappy->mapgnl[++y])
	{
		x = -1;
		while(mappy->mapgnl[y][++x])
		{
			if (mappy->mapgnl[y][x] == 'E')
			{
				j++;
			}
		}
	}
	if (j != 2)
		ft_error(3);	
}

void	allneed(t_map *mappy)
{
	Cneed(mappy);
	Pneed(mappy);
	Eneed(mappy);
}

void	fd_test(char *av)
{
	int	fd;
	
	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error(4);
	else
	close(fd);	
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
