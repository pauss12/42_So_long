/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_graphics_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:50:28 by pmendez-          #+#    #+#             */
/*   Updated: 2024/07/22 16:50:30 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	alternate_red_white_enemy(t_so_long *so_long, int x, int y)
{
	if (so_long->mlx->enemy_is_red)
		mlx_put_image_to_window(so_long->mlx->mlx, so_long->mlx->mlx_win,
			so_long->mlx->red_enemy, x, y);
	else
		mlx_put_image_to_window(so_long->mlx->mlx, so_long->mlx->mlx_win,
			so_long->mlx->white_enemy, x, y);
}

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
	else if (element == 'W')
		alternate_red_white_enemy(so_long, size_x, size_y);
}

static void	write_string_count_moves(t_so_long *so_long, int i)
{
	int		j;
	char	*temp;
	char	*aux;

	j = 0;
	temp = NULL;
	aux = NULL;
	while (j < so_long->width)
	{
		mlx_put_image_to_window(so_long->mlx->mlx, so_long->mlx->mlx_win,
			so_long->mlx->floor, j * 50, i * 50);
		j++;
	}
	temp = ft_itoa(so_long->moves);
	aux = ft_strjoin("Cantidad de Movimientos : ", temp);
	free(temp);
	if (!aux)
	{
		free(temp);
		free(aux);
		free_all(so_long);
	}
	mlx_string_put(so_long->mlx->mlx, so_long->mlx->mlx_win, (2 * 50),
		(so_long->height + 1) * 50 - 24, 0x000000, aux);
	free(aux);
}

void	draw_map(t_so_long *so_long)
{
	int		j;
	int		i;

	j = 0;
	i = 0;
	while (so_long->original_map[i + 1] != NULL)
	{
		j = 0;
		while (so_long->original_map[i][j] != '\0')
		{
			draw_one_element(so_long, so_long->original_map[i][j], j, i);
			j++;
		}
		i++;
	}
	write_string_count_moves(so_long, i);
}
