/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:49:49 by amait-ou          #+#    #+#             */
/*   Updated: 2023/10/05 16:50:33 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static	void	key_moves(t_game *game)
{
	if (mlx_is_key_down(game->mlx.mlx, MLX_KEY_W))
		move_up(game);
	if (mlx_is_key_down(game->mlx.mlx, MLX_KEY_S))
		move_down(game);
	if (mlx_is_key_down(game->mlx.mlx, MLX_KEY_A))
		move_left(game);
	if (mlx_is_key_down(game->mlx.mlx, MLX_KEY_D))
		move_right(game);
	if (mlx_is_key_down(game->mlx.mlx, MLX_KEY_RIGHT))
		game->player.rotation_angle += 0.03;
	if (mlx_is_key_down(game->mlx.mlx, MLX_KEY_LEFT))
		game->player.rotation_angle -= 0.03;
}

void	mouse_hook(double curr_x, void *g)
{
	static int	old_x;
	static int	i;
	t_game		*game;

	game = (t_game *)g;
	if (old_x == 0)
		old_x = curr_x;
	if (i++ == 1)
	{
		if (old_x > curr_x)
			game->player.rotation_angle -= 0.04;
		if (old_x < curr_x)
			game->player.rotation_angle += 0.04;
		i = 0;
		old_x = curr_x;
	}
	normalize_angle(&game->player.rotation_angle);
}

void	check_keys(void *game)
{
	t_game	*g;

	g = (t_game *)game;
	key_moves(g);
	if (mlx_is_key_down(g->mlx.mlx, MLX_KEY_ESCAPE))
	{
		ft_putendl_fd("\x1b[32m[+] You have exited the game", 1);
		free(g->rays);
		exit(0);
	}
	normalize_angle(&g->player.rotation_angle);
	render_game(game);
}
