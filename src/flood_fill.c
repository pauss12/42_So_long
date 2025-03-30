/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:21:03 by pmendez-          #+#    #+#             */
/*   Updated: 2024/07/12 14:21:04 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_can_be_solved(t_so_long *so_long)
{
	int	i;
	int	num_colectionables;

	i = 0;
	num_colectionables = so_long->num_colectionables;
	flood_fill(so_long, so_long->posx_player, so_long->posy_player);
	if (so_long->num_colectionables > 0)
	{
		ft_printf(RED "Error\n" END "Impossible get the collectionable\n");
		free_struct(so_long, NULL, 0, 1);
		return ;
	}
	while (i < so_long->height)
	{
		if (ft_strchr(so_long->copy_map[i], 'E') != 0)
		{
			ft_printf(RED "Error\n" END "Impossible to get to the exit\n");
			free_struct(so_long, NULL, 0, 1);
		}
		i++;
	}
	so_long->num_colectionables = num_colectionables;
}

void	flood_fill(t_so_long *so_long, int pos_x_player, int pos_y_player)
{
	if (pos_x_player < 0 || pos_y_player < 0 || pos_y_player >= so_long->width
		|| pos_x_player >= so_long->height
		|| so_long->copy_map[pos_x_player][pos_y_player] == '1'
		|| so_long->copy_map[pos_x_player][pos_y_player] == 'X')
		return ;
	if (so_long->copy_map[pos_x_player][pos_y_player] == 'C')
		so_long->num_colectionables--;
	if (so_long->copy_map[pos_x_player][pos_y_player] == 'E'
		&& so_long->num_colectionables > 0)
		return ;
	so_long->copy_map[pos_x_player][pos_y_player] = 'X';
	flood_fill(so_long, pos_x_player + 1, pos_y_player);
	flood_fill(so_long, pos_x_player - 1, pos_y_player);
	flood_fill(so_long, pos_x_player, pos_y_player + 1);
	flood_fill(so_long, pos_x_player, pos_y_player - 1);
}
