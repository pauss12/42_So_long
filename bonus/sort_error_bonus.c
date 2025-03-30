/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_error_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:50:54 by pmendez-          #+#    #+#             */
/*   Updated: 2024/07/22 16:50:55 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	types_of_ber_files(t_so_long *so_long, char *aux, char *temp)
{
	if (ft_strncmp(aux, ".ber", 5) != 0)
	{
		ft_putstr_fd(RED "Error\n" END "The file is not a .ber file\n", 2);
		free_all(so_long);
	}
	if (temp != aux)
	{
		ft_putstr_fd(RED "Error\n" END "Strange type of ber file\n", 2);
		free_all(so_long);
	}
}

void	check_error(t_so_long *so_long, char **argv)
{
	char	*aux;
	char	*temp;

	aux = ft_strrchr(argv[1], '.');
	temp = ft_strchr(argv[1], '.');
	if (aux == NULL)
	{
		ft_putstr_fd(RED "Error\n" END "The file has no extension\n", 2);
		free_all(so_long);
	}
	so_long->path_map = ft_strdup(argv[1]);
	if (so_long->path_map == NULL)
		free_all(so_long);
	types_of_ber_files(so_long, aux, temp);
	so_long->fd = open(argv[1], O_RDONLY);
	if (so_long->fd < 0)
	{
		ft_putstr_fd(RED "Error\n" END "The file does not exist\n", 2);
		free_all(so_long);
	}
	isvalid_map(so_long);
}

void	isvalid_map(t_so_long *so_long)
{
	int	i;

	i = 0;
	fill_map(so_long);
	check_if_rectangle(so_long);
	while (i < so_long->height)
	{
		check_line(so_long, so_long->copy_map[i], so_long->width);
		i++;
	}
	if (so_long == NULL || so_long->copy_map == NULL)
		free_all(so_long);
	check_surrounded_walls(so_long, so_long->width, so_long->height);
	if (so_long->num_entrance != 1 || so_long->num_exit != 1
		|| so_long->num_colectionables < 1
		|| so_long->num_enemies < 1)
	{
		ft_putstr_fd(RED "Error\n" END "There is an error in the Map\n", 2);
		free_struct(so_long, NULL, 0, 1);
	}
}

static int	comprobation(char *aux, t_so_long *so_long)
{
	int	num;

	num = ft_strlen(aux);
	if (so_long->height > 40 || num > 77)
	{
		ft_putstr_fd(RED "Error\n" END "The map is too big\n", 2);
		free_struct(so_long, NULL, 0, 1);
	}
	if (num == 0)
		return (-1);
	if (so_long->width != num)
	{
		ft_putstr_fd(RED "Error\n" END "The map is not a rectangle\n", 2);
		free_struct(so_long, NULL, 0, 1);
	}
	return (0);
}

void	check_if_rectangle(t_so_long *so_long)
{
	int	rows;

	rows = 0;
	while (so_long->copy_map[rows] != NULL)
	{
		if (comprobation(so_long->copy_map[rows], so_long) == -1)
			return ;
		else
			rows++;
	}
	if (so_long->height <= 0 || so_long->width <= 0)
	{
		ft_putstr_fd(RED "Error\n" END "The map is empty\n", 2);
		free_struct(so_long, NULL, 0, 1);
	}
}
