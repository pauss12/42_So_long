/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:41:18 by pmendez-          #+#    #+#             */
/*   Updated: 2024/07/25 23:41:19 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

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

void	fill_string(int lcount, t_so_long *so_long, char **temp, char **temp2)
{
	int	i;

	i = 0;
	while (i < lcount)
	{
		so_long->copy_map[i] = temp[i];
		so_long->original_map[i] = temp2[i];
		i++;
	}
	so_long->original_map[lcount] = ft_strdup("");
	so_long->copy_map[lcount] = NULL;
	so_long->original_map[lcount + 1] = NULL;
}

void	read_doc(t_so_long *so_long, char *aux, int lcount)
{
	char	*line;
	char	**temp;
	char	**temp2;

	line = get_next_line(so_long->fd);
	if (line == NULL)
	{
		close(so_long->fd);
		free(aux);
		ft_putstr_fd(RED "Error\n" END "The file is empty\n", 2);
		free_all(so_long);
	}
	aux = join_together(line, so_long, aux);
	temp = ft_split(aux, '\n');
	temp2 = ft_split(aux, '\n');
	while (temp[lcount] != NULL)
		lcount++;
	so_long->copy_map = (char **)malloc(sizeof(char *) * (lcount + 1));
	so_long->original_map = (char **)malloc(sizeof(char *) * (lcount + 2));
	fill_string(lcount, so_long, temp, temp2);
	free(temp);
	free(temp2);
	free(aux);
	close(so_long->fd);
}

void	fill_map(t_so_long *so_long)
{
	char	*aux;
	int		i;
	int		lcount;

	i = 0;
	lcount = 0;
	aux = ft_strdup("");
	if (aux == NULL)
	{
		close(so_long->fd);
		free_all(so_long);
		return ;
	}
	read_doc(so_long, aux, lcount);
	so_long->width = ft_strlen(so_long->copy_map[0]);
	while (so_long->copy_map[i] != NULL)
		i++;
	so_long->height = i;
}
