/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:26:54 by pmendez-          #+#    #+#             */
/*   Updated: 2024/07/03 12:26:55 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_all(t_so_long *so_long)
{
	free_mlx(so_long->mlx, 0);
	free_struct(so_long, NULL, 0, 1);
}

void	free_mlx(t_mlx *mlx, int failExit)
{
	if (mlx->floor)
		mlx_destroy_image(mlx->mlx, mlx->floor);
	if (mlx->wall)
		mlx_destroy_image(mlx->mlx, mlx->wall);
	if (mlx->colectionable)
		mlx_destroy_image(mlx->mlx, mlx->colectionable);
	if (mlx->player)
		mlx_destroy_image(mlx->mlx, mlx->player);
	if (mlx->exit)
		mlx_destroy_image(mlx->mlx, mlx->exit);
	if (mlx->mlx_win)
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	if (mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
	if (failExit == 1)
		exit(0);
	else
		return ;
}

void	free_struct(t_so_long *so_long, char *aux, int freeAux, int failExit)
{
	if (so_long->mlx)
		free(so_long->mlx);
	if (so_long->path_map)
		free(so_long->path_map);
	if (so_long->original_map != NULL)
		free_double_str(so_long->original_map);
	if (so_long->copy_map != NULL)
		free_double_str(so_long->copy_map);
	if (so_long)
		free(so_long);
	if (freeAux == 1)
		free(aux);
	if (failExit == 1)
		exit(0);
}

void	free_double_str(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
