/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:49:49 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/03 03:39:51 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_keys(void *game)
{
	t_game	*g;

	g = (t_game *)game;
	if (mlx_is_key_down(g->mlx.mlx, MLX_KEY_W))
		move_up(g);
	if (mlx_is_key_down(g->mlx.mlx, MLX_KEY_S))
		move_down(g);
	if (mlx_is_key_down(g->mlx.mlx, MLX_KEY_A))
		move_left(g);
	if (mlx_is_key_down(g->mlx.mlx, MLX_KEY_D))
		move_right(g);
	if (mlx_is_key_down(g->mlx.mlx, MLX_KEY_RIGHT))
		g->player.rotation_angle += 0.03;
	if (mlx_is_key_down(g->mlx.mlx, MLX_KEY_LEFT))
		g->player.rotation_angle -= 0.03;
	if (mlx_is_key_down(g->mlx.mlx, MLX_KEY_ESCAPE))
	{
		ft_putendl_fd("\x1b[32m[+] You have exited the game", 1);
		free(g->rays);
		exit(0);
	}
	normalize_angle(&g->player.rotation_angle);
	render_game(game);
}
