/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_calculations_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalil- <ykhalil-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 02:49:22 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/06 11:30:26 by ykhalil-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	fix_fish_eye(t_game *game, int index)
{
	game->rays[index].distance *= cos(game->player.rotation_angle
			- game->rays[index].angle);
}

void	calculate_wall_height(t_game *game, int index)
{
	game->rays[index].wall_height = (WINDOW_HEIGHT
			/ game->rays[index].distance) * WALL_STRIP_WIDTH;
}

void	calculate_starting_point_of_the_wall(t_game *game, int index)
{
	game->rays[index].y_start = (WINDOW_HEIGHT / 2.0)
		- (game->rays[index].wall_height / 2.0);
}

void	calculate_ending_point_of_the_wall(t_game *game, int index)
{
	game->rays[index].y_end = game->rays[index].y_start
		+ game->rays[index].wall_height;
}
