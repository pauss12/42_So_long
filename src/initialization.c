/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:21:16 by pmendez-          #+#    #+#             */
/*   Updated: 2024/07/12 14:21:17 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
}
