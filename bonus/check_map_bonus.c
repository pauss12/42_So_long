/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:49:36 by pmendez-          #+#    #+#             */
/*   Updated: 2024/07/22 16:49:37 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	count_characters(t_so_long **so_long, char c)
{
	if (c == 'C')
		(*so_long)->num_colectionables++;
	if (c == 'E')
		(*so_long)->num_exit++;
	if (c == 'P')
		(*so_long)->num_entrance++;
	if (c == 'W')
		(*so_long)->num_enemies++;
}

void	check_line(t_so_long *so_long, char *aux, int cols)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (i < cols)
	{
		if (aux[j] != '1' && aux[j] != '0' && aux[j] != 'P' && aux[j] != 'E'
			&& aux[j] != 'C' && aux[j] != 'W')
		{
			ft_printf(RED "Error\n" END "Invalid character in the map\n");
			close(so_long->fd);
			free_struct(so_long, NULL, 0, 1);
			return ;
		}
		count_characters(&so_long, aux[j]);
		j++;
		i++;
	}
}

void	check_surrounded_walls(t_so_long *so_long, int cols, int rows)
{
	int	i;
	int	j;

	i = 0;
	j = cols - 1;
	while (i < rows)
	{
		if (so_long->copy_map[i][0] != '1' || so_long->copy_map[i][j] != '1')
		{
			ft_putstr_fd(RED "Error\n" END "Not surrounded by walls\n", 2);
			free_struct(so_long, NULL, 0, 1);
		}
		i++;
	}
	j = 0;
	i = rows - 1;
	while (j < cols)
	{
		if (so_long->copy_map[0][j] != '1' || so_long->copy_map[i][j] != '1')
		{
			ft_putstr_fd(RED "Error\n" END "Not surrounded by walls\n", 2);
			free_struct(so_long, NULL, 0, 1);
		}
		j++;
	}
}
