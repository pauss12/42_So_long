/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:21:24 by pmendez-          #+#    #+#             */
/*   Updated: 2024/07/12 14:21:25 by pmendez-         ###   ########.fr       */
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
