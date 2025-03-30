/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:23:45 by pmendez-          #+#    #+#             */
/*   Updated: 2024/07/24 16:23:46 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	*ft_free_join(char *str, char *buffer)
{
	char	*aux;

	aux = ft_strjoin(str, buffer);
	if (aux == NULL)
	{
		free(str);
		free(buffer);
		return (NULL);
	}
	free(str);
	return (aux);
}

static void	check_if_full_new_line(t_so_long *so_long, char *aux)
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

static char	*join_together(char *line, t_so_long *so_long, char *aux)
{
	while (line != NULL)
	{
		aux = ft_free_join(aux, line);
		if (aux == NULL)
		{
			close(so_long->fd);
			free(line);
			free(aux);
			free_all(so_long);
		}
		free(line);
		line = get_next_line(so_long->fd);
	}
	check_if_full_new_line(so_long, aux);
	return (aux);
}

void	read_doc(t_so_long *so_long, char *aux)
{
	char	*line;

	line = get_next_line(so_long->fd);
	if (line == NULL)
	{
		close(so_long->fd);
		free(aux);
		ft_putstr_fd(RED "Error\n" END "The file is empty\n", 2);
		free_all(so_long);
	}
	aux = join_together(line, so_long, aux);
	so_long->copy_map = ft_split(aux, '\n');
	so_long->original_map = ft_split(aux, '\n');
	free(aux);
	close(so_long->fd);
}

void	fill_map(t_so_long *so_long)
{
	char	*aux;
	int		i;

	i = 0;
	aux = ft_strdup("");
	if (aux == NULL)
	{
		close(so_long->fd);
		free_all(so_long);
		return ;
	}
	read_doc(so_long, aux);
	so_long->width = ft_strlen(so_long->copy_map[0]);
	while (so_long->copy_map[i] != NULL)
		i++;
	so_long->height = i;
}
