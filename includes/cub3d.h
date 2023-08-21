/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:55:08 by amait-ou          #+#    #+#             */
/*   Updated: 2023/08/21 22:28:48 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../superlib/superlib.h"
# include <math.h>
# include <fcntl.h>
# include "../mlx/include/MLX42/MLX42.h"

typedef enum e_enums
{
	_NORTH,
	_WEST,
	_SOUTH,
	_EAST,
	_COLOR_F,
	_COLOR_C,
	_NONE
}	t_enums;

typedef struct s_north
{
	char			*texture;
	t_enums			direction;
}	t_north;

typedef struct s_west
{
	char			*texture;
	t_enums			direction;
}	t_west;

typedef struct s_south
{
	char			*texture;
	t_enums			direction;
}	t_south;

typedef struct s_east
{
	char			*texture;
	t_enums			direction;
}	t_east;

typedef struct s_color_f
{
	char	*surface;
	char	*rgb;
	t_enums	type;
}	t_color_f;

typedef struct s_color_c
{
	char	*surface;
	char	*rgb;
	t_enums	type;
}	t_color_c;

typedef struct s_elements
{
	int			counter;
	t_north		north;
	t_east		east;
	t_south		south;
	t_west		west;
	t_color_f	floor_c;
	t_color_c	ceiling_c;
}	t_elements;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_game
{
	int				west;
	int				east;
	int				south;
	int				north;
	char			**all_items;
	char			*lines;
	char			**map;
	int				len;
	char			*path;
	int				fd;
	t_elements		elements;
	t_player		player;
}	t_game;

// reader
int		__reader(t_game *game);

// parser
void	init_elements(t_game *game);
void	assign_color(t_game *game, char **element);
void	assign_directions(t_game *game, char **element);
int		lines_count(t_game *game);
int		parse_elements(t_game *game);
int		parse_map(t_game *game);
int		__parser(t_game *game);

// displayer
void	__display_items(t_game *game);
void	__display_elements(t_game *game);
void	__display_map(t_game *game);

// leaks
void	free_array(char **arr);

// error
int		check_reader(t_game *game);
int		check_parser(t_game *game);
int		check_elements(t_game *game);
int		check_map(t_game *game);
int		check_map_helper(t_game *game, int i, int j);
// int		check_walls(t_game *game);
int		__checker(t_game *game);
void	error_helper(t_game *game, char d, int x, int y);
#endif
