/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_graphics.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:21:44 by pmendez-          #+#    #+#             */
/*   Updated: 2024/07/12 14:21:45 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_one_element(t_so_long *so_long, char element, int x, int y)
{
	int	size_x;
	int	size_y;
	int	size;

	size = SIZE;
	size_x = x * size;
	size_y = y * size;
	if (element == '1')
		mlx_put_image_to_window(so_long->mlx->mlx, so_long->mlx->mlx_win,
			so_long->mlx->wall, size_x, size_y);
	else if (element == '0')
		mlx_put_image_to_window(so_long->mlx->mlx, so_long->mlx->mlx_win,
			so_long->mlx->floor, size_x, size_y);
	else if (element == 'C')
		mlx_put_image_to_window(so_long->mlx->mlx, so_long->mlx->mlx_win,
			so_long->mlx->colectionable, size_x, size_y);
	else if (element == 'E')
		mlx_put_image_to_window(so_long->mlx->mlx, so_long->mlx->mlx_win,
			so_long->mlx->exit, size_x, size_y);
	else if (element == 'P')
		mlx_put_image_to_window(so_long->mlx->mlx, so_long->mlx->mlx_win,
			so_long->mlx->player, size_x, size_y);
}

void	draw_map(t_so_long *so_long)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (so_long->original_map[i] != NULL)
	{
		j = 0;
		while (so_long->original_map[i][j] != '\0')
		{
			draw_one_element(so_long, so_long->original_map[i][j], j, i);
			j++;
		}
		i++;
	}
}
