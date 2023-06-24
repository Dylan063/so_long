/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravaono <dravaono@student42nice.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 06:21:49 by dravaono          #+#    #+#             */
/*   Updated: 2023/06/19 17:45:52 by dravaono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	sizemap(t_map *mappy, char *av)
{
	int		fd;
	char	*mapline;
	
	fd = open(av, O_RDONLY);
	mapline = get_next_line(fd);
	mappy->linemap = 0;
	while (mapline)
	{
		free(mapline);
		mappy->linemap++;
		mapline = get_next_line(fd);
	}
	close(fd);
}

void	cpymap(t_map *mappy, char *av)
{
	int	fd;
	int	y;

	fd = open(av, O_RDONLY);
	mappy->mapgnl = malloc((sizeof(char *) + 1) * mappy->linemap);
	y = 0;
	mappy->mapgnl[y] = get_next_line(fd);
	while(++y < mappy->linemap)
		mappy->mapgnl[y] = get_next_line(fd);
	mappy->mapgnl[y] = NULL;
	close(fd);
}

void	ft_error(int a)
{
	if (a == 1)
		ft_printf("Error\nbad size of map\n");
	else if (a == 2)
		ft_printf("Error\nneed wall for play/n");
	else if (a == 3)
		ft_printf("Error\nmap incomplete");
	else if (a == 4)
		ft_printf("Error\nneed a fd");
	else if (a == 5)
		ft_printf("Error\nchange name");
	else if (a == 6)
		ft_printf("Error\nbad path");
	else if (a == 7)
		ft_printf("Error\ncan't find texture");
	else if (a == 8)
		ft_printf("Error\ncan't open window");
	exit(1);
	
}

//fr un open si c un fd et pas un doss si open renvoi -1 ft error else close fd et ouverture map
