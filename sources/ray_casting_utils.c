/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:24:33 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/28 08:01:45 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	radial(float number)
{
	return (number * (M_PI / 180.0));
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	clear_map(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		j = 0;
		while (j < WINDOW_HEIGHT)
		{
			mlx_put_pixel(game->mlx.window, i, j, 0);
			++j;
		}
		++i;
	}
}

void	draw_floor(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < WINDOW_HEIGHT / 2)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			mlx_put_pixel(game->mlx.window, j, i, get_rgba(38, 77, 69, 255));
			++j;
		}
		++i;
	}
}

void	draw_ceiling(t_game *game)
{
	size_t	i;
	size_t	j;

	i = WINDOW_HEIGHT / 2;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			mlx_put_pixel(game->mlx.window, j, i, get_rgba(130, 108, 56, 255));
			++j;
		}
		++i;
	}
}