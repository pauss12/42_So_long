/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_moves_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:49:42 by pmendez-          #+#    #+#             */
/*   Updated: 2024/07/22 16:49:43 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	move_left(t_so_long *so_long)
{
	long long	i;

	i = 0;
	mlx_put_image_to_window(so_long->mlx->mlx, so_long->mlx->mlx_win,
		so_long->mlx->player_left, so_long->posy_player * SIZE,
		so_long->posx_player * SIZE);
	mlx_do_sync(so_long->mlx->mlx);
	while (i < WAIT_TIME)
		i++;
	move_player(so_long, so_long->posx_player, so_long->posy_player - 1);
	mlx_put_image_to_window(so_long->mlx->mlx, so_long->mlx->mlx_win,
		so_long->mlx->player, so_long->posy_player * SIZE,
		so_long->posx_player * SIZE);
}

static void	move_up(t_so_long *so_long)
{
	long long	i;

	i = 0;
	mlx_put_image_to_window(so_long->mlx->mlx, so_long->mlx->mlx_win,
		so_long->mlx->player_up, so_long->posy_player * SIZE,
		so_long->posx_player * SIZE);
	mlx_do_sync(so_long->mlx->mlx);
	while (i < WAIT_TIME)
		i++;
	move_player(so_long, so_long->posx_player - 1, so_long->posy_player);
	mlx_put_image_to_window(so_long->mlx->mlx, so_long->mlx->mlx_win,
		so_long->mlx->player, so_long->posy_player * SIZE,
		so_long->posx_player * SIZE);
}

static void	move_right(t_so_long *so_long)
{
	long long	i;

	i = 0;
	mlx_put_image_to_window(so_long->mlx->mlx, so_long->mlx->mlx_win,
		so_long->mlx->player_right, so_long->posy_player * SIZE,
		so_long->posx_player * SIZE);
	mlx_do_sync(so_long->mlx->mlx);
	while (i < WAIT_TIME)
		i++;
	move_player(so_long, so_long->posx_player, so_long->posy_player + 1);
	mlx_put_image_to_window(so_long->mlx->mlx, so_long->mlx->mlx_win,
		so_long->mlx->player, so_long->posy_player * SIZE,
		so_long->posx_player * SIZE);
}

static int	handle_key_press(int key, void *param)
{
	t_so_long	*so_long;
	int			num_enemies;

	so_long = (t_so_long *)param;
	num_enemies = so_long->num_enemies;
	if (key == LEFT_A || key == LEFT_ARROW)
		move_left(so_long);
	else if (key == UP_W || key == UP_ARROW)
		move_up(so_long);
	else if (key == DOWN_S || key == DOWN_ARROW)
		move_player(so_long, so_long->posx_player + 1, so_long->posy_player);
	else if (key == RIGHT_D || key == RIGHT_ARROW)
		move_right(so_long);
	else if (key == ESC)
	{
		close_window(param);
		return (0);
	}
	if (so_long->num_enemies < num_enemies)
		ft_printf("You have been KILLED by the enemy\n");
	if (so_long->exit_game == 1)
		mlx_loop_end(so_long->mlx->mlx);
	return (0);
}

void	start_game(t_so_long *so_long)
{
	mlx_hook(so_long->mlx->mlx_win, 17, 0, close_window, so_long);
	mlx_hook(so_long->mlx->mlx_win, 2, 1L << 0, handle_key_press, so_long);
	mlx_loop_hook(so_long->mlx->mlx, update, so_long);
	mlx_loop(so_long->mlx->mlx);
}
