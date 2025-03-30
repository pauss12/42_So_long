/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:53:15 by pmendez-          #+#    #+#             */
/*   Updated: 2024/07/14 13:53:16 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define RED "\033[0;31m"
# define END "\033[0m"

# define RIGHT_D 100
# define LEFT_A 97
# define UP_W 119
# define DOWN_S 115
# define UP_ARROW 65362
# define DOWN_ARROW 65364
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define ESC 65307

# define SIZE 50

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*floor;
	void	*wall;
	void	*colectionable;
	void	*player;
	void	*exit;
}	t_mlx;

typedef struct s_so_long
{
	int		fd;
	char	*path_map;
	char	**original_map;
	char	**copy_map;
	int		num_colectionables;
	int		num_exit;
	int		num_entrance;
	int		posx_player;
	int		posy_player;
	int		height;
	int		width;
	t_mlx	*mlx;
	int		moves;
	int		exit_game;
}	t_so_long;

//initialization.c
void	initialize_all_variables(t_so_long **so_long);
void	initialize_sprites(t_so_long **so_long);

// prepare_sprites.c
void	create_textures(t_so_long *so_long);

//put_in_graphics.c
void	draw_map(t_so_long *so_long);
void	draw_one_element(t_so_long *so_long, char element, int x, int y);

//control_moves.c
void	start_game(t_so_long *so_long);
void	move_player(t_so_long *so_long, int pos_x, int pos_y);

// sort_error_file.c
void	check_error(t_so_long *so_long, char **argv);
void	check_if_rectangle(t_so_long *so_long);
void	isvalid_map(t_so_long *so_long);

//check_map.c
void	check_line(t_so_long *so_long, char *aux, int columns);
void	check_surrounded_walls(t_so_long *so_long, int columns, int rows);

//fill_map.c
void	fill_map(t_so_long *so_long);
void	read_doc(t_so_long *so_long, char *aux);

// flood_fill.c
void	check_can_be_solved(t_so_long *so_long);
void	flood_fill(t_so_long *so_long, int pos_x_player, int pos_y_player);

//utils.c
void	print_map(char **map);
void	find_player(t_so_long *so_long);
int		close_window(void *param);

//free_memory.c
void	free_struct(t_so_long *so_long, char *aux, int freeAux, int failExit);
void	free_mlx(t_mlx *mlx, int failExit);
void	free_all(t_so_long *so_long);
void	free_double_str(char **str);

#endif