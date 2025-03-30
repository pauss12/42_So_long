/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:49:48 by pmendez-          #+#    #+#             */
/*   Updated: 2024/07/22 16:49:49 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	check_can_be_solved(t_so_long *so_long)
{
	int	i;
	int	num_colectionables;
	int	n_enemies;

	i = 0;
	n_enemies = so_long->num_enemies;
	num_colectionables = so_long->num_colectionables;
	flood_fill(so_long, so_long->posx_player, so_long->posy_player, n_enemies);
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
	so_long->num_enemies = n_enemies;
}

void	flood_fill(t_so_long *so_long, int pos_x, int pos_y, int n_enemies)
{
	if (so_long->copy_map[pos_x][pos_y] == 'W')
		so_long->num_enemies--;
	if (pos_x < 0 || pos_y < 0
		|| pos_y >= so_long->width
		|| pos_x >= so_long->height - 1
		|| so_long->copy_map[pos_x][pos_y] == '1'
		|| so_long->copy_map[pos_x][pos_y] == 'X'
		|| so_long->copy_map[pos_x][pos_y] == 'W')
		return ;
	if (so_long->copy_map[pos_x][pos_y] == 'C')
		so_long->num_colectionables--;
	if (so_long->copy_map[pos_x][pos_y] == 'E'
		&& so_long->num_colectionables > 0
		&& so_long->num_enemies == n_enemies)
		return ;
	so_long->copy_map[pos_x][pos_y] = 'X';
	flood_fill(so_long, pos_x, pos_y + 1, n_enemies);
	flood_fill(so_long, pos_x, pos_y - 1, n_enemies);
	flood_fill(so_long, pos_x + 1, pos_y, n_enemies);
	flood_fill(so_long, pos_x - 1, pos_y, n_enemies);
}
