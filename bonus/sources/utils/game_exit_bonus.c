/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:29:23 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/06 16:04:49 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	mlx_exit(t_game *game)
{
	clear_map(game);
	mlx_delete_image(game->mlx.mlx, game->mlx.image);
	mlx_close_window(game->mlx.mlx);
}