/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:50:02 by pmendez-          #+#    #+#             */
/*   Updated: 2024/07/22 16:50:03 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	initialize_all_variables(t_so_long **so_long)
{
	*so_long = malloc(1 * sizeof(t_so_long));
	if (*so_long == NULL)
		return ;
	(*so_long)->mlx = NULL;
	(*so_long)->copy_map = NULL;
	(*so_long)->original_map = NULL;
	(*so_long)->height = 0;
	(*so_long)->num_colectionables = 0;
	(*so_long)->num_enemies = 0;
	(*so_long)->num_entrance = 0;
	(*so_long)->num_exit = 0;
	(*so_long)->path_map = NULL;
	(*so_long)->posx_player = 0;
	(*so_long)->posy_player = 0;
	(*so_long)->width = 0;
	(*so_long)->exit_game = 0;
	(*so_long)->moves = 0;
	initialize_sprites(so_long);
}

void	initialize_sprites(t_so_long **so_long)
{
	(*so_long)->mlx = malloc(sizeof(t_mlx));
	if ((*so_long)->mlx == NULL)
	{
		free_all(*so_long);
		*so_long = NULL;
		return ;
	}
	(*so_long)->mlx->mlx = NULL;
	(*so_long)->mlx->mlx_win = NULL;
	(*so_long)->mlx->floor = NULL;
	(*so_long)->mlx->wall = NULL;
	(*so_long)->mlx->colectionable = NULL;
	(*so_long)->mlx->player = NULL;
	(*so_long)->mlx->exit = NULL;
	(*so_long)->mlx->red_enemy = NULL;
	(*so_long)->mlx->white_enemy = NULL;
	(*so_long)->mlx->player_left = NULL;
	(*so_long)->mlx->player_right = NULL;
	(*so_long)->mlx->player_up = NULL;
	(*so_long)->mlx->enemy_is_red = 1;
	(*so_long)->mlx->counter = 0;
}
