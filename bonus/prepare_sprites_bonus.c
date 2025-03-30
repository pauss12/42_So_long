/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_sprites_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:50:20 by pmendez-          #+#    #+#             */
/*   Updated: 2024/07/22 16:50:21 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

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

void	prepare_other_sprites(t_so_long *so_long)
{
	int	size;

	size = SIZE;
	so_long->mlx->player_left = mlx_xpm_file_to_image(so_long->mlx->mlx,
			"textures/player_looking_left.xpm", &size, &size);
	if (!so_long->mlx->player_left)
		show_error_textures(so_long);
	so_long->mlx->player_right = mlx_xpm_file_to_image(so_long->mlx->mlx,
			"textures/player_looking_right.xpm", &size, &size);
	if (!so_long->mlx->player_right)
		show_error_textures(so_long);
	so_long->mlx->player_up = mlx_xpm_file_to_image(so_long->mlx->mlx,
			"textures/player_looking_up.xpm", &size, &size);
	if (!so_long->mlx->player_up)
		show_error_textures(so_long);
	so_long->mlx->red_enemy = mlx_xpm_file_to_image(so_long->mlx->mlx,
			"textures/red_enemy.xpm", &size, &size);
	if (!so_long->mlx->red_enemy)
		show_error_textures(so_long);
	so_long->mlx->white_enemy = mlx_xpm_file_to_image(so_long->mlx->mlx,
			"textures/white_enemy.xpm", &size, &size);
	if (!so_long->mlx->white_enemy)
		show_error_textures(so_long);
}
