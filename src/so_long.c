/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:54:38 by pmendez-          #+#    #+#             */
/*   Updated: 2024/06/28 20:54:39 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	initialize_mlx(t_so_long *so_long)
{
	int	width;
	int	height;
	int	size;

	size = SIZE;
	width = so_long->width * size;
	height = so_long->height * size;
	so_long->mlx->mlx = mlx_init();
	if (!so_long->mlx->mlx)
		free_struct(so_long, NULL, 0, 1);
	so_long->mlx->mlx_win = mlx_new_window(so_long->mlx->mlx,
			width, height, "SO LONG");
	if (!so_long->mlx->mlx_win)
		free_struct(so_long, NULL, 0, 1);
	create_textures(so_long);
	draw_map(so_long);
	start_game(so_long);
}

int	main(int argc, char *argv[])
{
	t_so_long	*so_long;

	so_long = NULL;
	if (argc != 2)
	{
		ft_putstr_fd(RED "Error\n" END "Invalid number of arguments\n", 2);
		ft_putstr_fd("Usage: ./so_long [map.ber]\n", 2);
		exit(0);
	}
	initialize_all_variables(&so_long);
	check_error(so_long, argv);
	find_player(so_long);
	check_can_be_solved(so_long);
	initialize_mlx(so_long);
	free_all(so_long);
	return (0);
}
