/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:21:37 by pmendez-          #+#    #+#             */
/*   Updated: 2024/07/12 14:21:38 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	show_error_textures(t_so_long *so_long)
{
	ft_printf(RED "Error\n" END "Image cannot be loaded\n");
	free_all(so_long);
}

void	create_textures(t_so_long *so_long)
{
	int	size;

	size = SIZE;
	so_long->mlx->floor = mlx_xpm_file_to_image(so_long->mlx->mlx,
			"textures/floor.xpm", &size, &size);
	if (!so_long->mlx->floor)
		show_error_textures(so_long);
	so_long->mlx->wall = mlx_xpm_file_to_image(so_long->mlx->mlx,
			"textures/wall.xpm", &size, &size);
	if (!so_long->mlx->wall)
		show_error_textures(so_long);
	so_long->mlx->colectionable = mlx_xpm_file_to_image(so_long->mlx->mlx,
			"textures/coleccionable.xpm", &size, &size);
	if (!so_long->mlx->colectionable)
		show_error_textures(so_long);
	so_long->mlx->exit = mlx_xpm_file_to_image(so_long->mlx->mlx,
			"textures/exit.xpm", &size, &size);
	if (!so_long->mlx->exit)
		show_error_textures(so_long);
	so_long->mlx->player = mlx_xpm_file_to_image(so_long->mlx->mlx,
			"textures/player.xpm", &size, &size);
	if (!so_long->mlx->player)
		show_error_textures(so_long);
}
