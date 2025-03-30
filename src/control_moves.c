/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:20:55 by pmendez-          #+#    #+#             */
/*   Updated: 2024/07/12 14:20:56 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	possible_exit(t_so_long *so_long, int pos_x, int pos_y)
{
	if (so_long->num_colectionables == 0)
	{
		so_long->moves++;
		ft_printf("The player has moved %d times\n", so_long->moves);
		so_long->exit_game = 1;
		return ;
	}
	else
	{
		so_long->original_map[pos_x][pos_y] = 'E';
		so_long->original_map[so_long->posx_player][so_long->posy_player] = 'P';
	}
}

static void	if_there_is_nothing(t_so_long *so_long, int pos_x, int pos_y)
{
	so_long->original_map[so_long->posx_player][so_long->posy_player] = '0';
	so_long->original_map[pos_x][pos_y] = 'P';
	so_long->posx_player = pos_x;
	so_long->posy_player = pos_y;
	so_long->moves++;
}

void	move_player(t_so_long *so_long, int pos_x, int pos_y)
{
	if (!(pos_y >= 0 && so_long->original_map[pos_x][pos_y] != '1'))
		return ;
	if (so_long->original_map[pos_x][pos_y] == 'C')
	{
		so_long->num_colectionables--;
		so_long->original_map[so_long->posx_player][so_long->posy_player] = '0';
		so_long->original_map[pos_x][pos_y] = 'P';
	}
	if (so_long->original_map[pos_x][pos_y] == 'E')
	{
		possible_exit(so_long, pos_x, pos_y);
		return ;
	}
	else
		if_there_is_nothing(so_long, pos_x, pos_y);
	draw_map(so_long);
	ft_printf("The player has moved %d times\n", so_long->moves);
}

static int	handle_key_press(int key, void *param)
{
	t_so_long	*so_long;

	so_long = (t_so_long *)param;
	if (key == LEFT_A || key == LEFT_ARROW)
		move_player(so_long, so_long->posx_player, so_long->posy_player - 1);
	else if (key == UP_W || key == UP_ARROW)
		move_player(so_long, so_long->posx_player - 1, so_long->posy_player);
	else if (key == DOWN_S || key == DOWN_ARROW)
		move_player(so_long, so_long->posx_player + 1, so_long->posy_player);
	else if (key == RIGHT_D || key == RIGHT_ARROW)
		move_player(so_long, so_long->posx_player, so_long->posy_player + 1);
	else if (key == ESC)
	{
		mlx_loop_end(so_long->mlx->mlx);
		free_mlx(so_long->mlx, 0);
		free_struct(so_long, NULL, 0, 1);
	}
	if (so_long->exit_game == 1)
		mlx_loop_end(so_long->mlx->mlx);
	return (0);
}

void	start_game(t_so_long *so_long)
{
	mlx_hook(so_long->mlx->mlx_win, 17, 0, close_window, so_long);
	mlx_hook(so_long->mlx->mlx_win, 2, 1L << 0, handle_key_press, so_long);
	mlx_loop(so_long->mlx->mlx);
}
