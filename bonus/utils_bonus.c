/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:51:04 by pmendez-          #+#    #+#             */
/*   Updated: 2024/07/22 16:51:05 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	close_window(void *param)
{
	t_so_long	*so_long;

	so_long = (t_so_long *)param;
	if (so_long == NULL)
	{
		ft_printf(RED "Error\n" END "so_long es NULL\n");
		return (0);
	}
	mlx_loop_end(so_long->mlx->mlx);
	free_mlx(so_long->mlx, 0);
	free_struct(so_long, NULL, 0, 1);
	return (0);
}

void	check_if_full_new_line(t_so_long *so_long, char *aux)
{
	int	i;

	i = 0;
	while (i < ft_strlen(aux))
	{
		if (aux[i] != '\n')
			break ;
		i++;
	}
	if (i == ft_strlen(aux))
	{
		close(so_long->fd);
		free(aux);
		ft_putstr_fd(RED "Error\n" END "The file is empty\n", 2);
		free_all(so_long);
	}
}

int	update(t_so_long *so_long)
{
	so_long->mlx->counter++;
	if (so_long->mlx->counter >= 20000)
	{
		so_long->mlx->enemy_is_red = !so_long->mlx->enemy_is_red;
		so_long->mlx->counter = 0;
		draw_map(so_long);
	}
	return (0);
}

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
		{
			ft_putchar_fd(map[i][j], 1);
			j++;
		}
		ft_putchar_fd('\n', 2);
		j = 0;
		i++;
	}
}

void	find_player(t_so_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (so_long->original_map[i] != NULL)
	{
		j = 0;
		while (so_long->original_map[i][j] != '\0')
		{
			if (so_long->original_map[i][j] == 'P')
			{
				so_long->posx_player = i;
				so_long->posy_player = j;
				return ;
			}
			j++;
		}
		i++;
	}
}
