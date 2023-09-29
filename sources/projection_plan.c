/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_plan.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:54:57 by amait-ou          #+#    #+#             */
/*   Updated: 2023/09/28 17:42:42 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	projection_plan(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		game->player.distance = sqrt(pow(game->ray[i].y
					- game->player.y, 2.0)
				+ pow(game->ray[i].x - game->player.x, 2.0));
		game->player.distance *= cos(game->ray[i].angle
				- game->player.rotation_angle);
		game->player.wall_height = (WINDOW_HEIGHT
				/ game->player.distance) * 13;
		if (game->player.wall_height > WINDOW_HEIGHT)
			game->player.wall_height = WINDOW_HEIGHT;
		game->player.y_start = (WINDOW_HEIGHT / 2.0)
			- (game->player.wall_height / 2.0);
		game->player.y_end = game->player.y_start + game->player.wall_height;
		while (game->player.y_start < game->player.y_end)
		{
			mlx_put_pixel(game->mlx.window, i, game->player.y_start,
				get_rgba(158, 118, 171, 255));
			game->player.y_start++;
		}
		++i;
	}
}