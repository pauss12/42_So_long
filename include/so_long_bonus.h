/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:49:22 by pmendez-          #+#    #+#             */
/*   Updated: 2024/07/22 16:49:23 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
# define WAIT_TIME 15200000

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*floor;
	void	*wall;
	void	*colectionable;
	void	*player;
	void	*exit;
	void	*red_enemy;
	void	*player_left;
	void	*player_right;
	void	*player_up;
	void	*white_enemy;
	int		enemy_is_red;
	int		counter;
}	t_mlx;

typedef struct s_so_long
{
	int		fd;
	char	*path_map;
	char	**original_map;
	char	**copy_map;
	int		num_colectionables;
	int		num_enemies;
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

// initialization_bonus.c
void	initialize_all_variables(t_so_long **so_long);
void	initialize_sprites(t_so_long **so_long);

// prepare_sprites_bonus.c
void	create_textures(t_so_long *so_long);
void	prepare_other_sprites(t_so_long *so_long);

// put_in_graphics_bonus.c
void	draw_map(t_so_long *so_long);
void	draw_one_element(t_so_long *so_long, char element, int x, int y);

// control_moves_bonus.c
void	start_game(t_so_long *so_long);

// sort_error_bonus.c
void	check_if_rectangle(t_so_long *so_long);
void	isvalid_map(t_so_long *so_long);
void	check_error(t_so_long *so_long, char **argv);

// check_map_bonus.c
void	check_line(t_so_long *so_long, char *aux, int columns);
void	check_surrounded_walls(t_so_long *so_long, int columns, int rows);

// fill_map_bonus.c
void	fill_map(t_so_long *so_long);
void	read_doc(t_so_long *so_long, char *aux, int lcount);
void	fill_string(int lcount, t_so_long *so_long, char **temp, char **temp2);

// flood_fill_bonus.c
void	check_can_be_solved(t_so_long *so_long);
void	flood_fill(t_so_long *so_long, int pos_x, int pos_y, int n_enemies);

// utils_bonus.c
void	print_map(char **map);
void	find_player(t_so_long *so_long);
int		close_window(void *param);
int		update(t_so_long *so_long);
void	check_if_full_new_line(t_so_long *so_long, char *aux);

// free_memory_bonus.c
void	free_struct(t_so_long *so_long, char *aux, int freeAux, int failExit);
void	free_mlx(t_mlx *mlx, int failExit);
void	free_all(t_so_long *so_long);
void	free_double_str(char **str);

// moves_player_bonus.c
void	move_player(t_so_long *so_long, int pos_x, int pos_y);

#endif
