/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravaono <dravaono@student42nice.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 06:31:00 by dravaono          #+#    #+#             */
/*   Updated: 2023/06/23 16:46:52 by dravaono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft/inc/libft.h"
# include "libft/inc/get_next_line.h"
# include "libft/inc/ft_printf.h"

typedef struct s_map
{
	char			**mapgnl;
	int				linemap;
	size_t			lenline;
}			t_map;

typedef struct s_img
{
	void	*mario;
	void	*collec;
	void	*wall;
	void	*floor;
	void	*exit;
}	t_img;

typedef struct s_game
{
	int		conso;
	int		playerx;
	int		playery;
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	t_img	img;
}	t_game;

// parsing

void		sizemap(t_map *mappy, char *av);
void		cpymap(t_map *mappy, char *av);
void		parsing(t_map *mappy, char *av);
void		fd_test(char *av);
void		ft_error(int a);
void		samelen(t_map *mappy);
void		wall(t_map *mappy);
void		allneed(t_map *mappy);
char		**cpy_path(t_map *mappy);
void		search_path(t_map *mappy);
void		change_s(char **mappath, int y, int x);

// mlx

void	init_mlx(t_game *game);


#endif

