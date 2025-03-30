# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/28 20:54:28 by pmendez-          #+#    #+#              #
#    Updated: 2024/06/28 20:54:29 by pmendez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address,leak
FLAGS_MLX = -Lmlx -lmlx -L/usr/lib/x11 -lXext -lX11

FILES = src/so_long.c \
		src/sort_error_file.c \
		src/utils.c \
		src/free_memory.c \
		src/check_map.c \
		src/flood_fill.c \
		src/prepare_sprites.c \
		src/put_in_graphics.c \
		src/control_moves.c \
		src/initialization.c \
		src/fill_map.c

FILES_BONUS =	bonus/so_long_bonus.c \
				bonus/sort_error_bonus.c \
				bonus/utils_bonus.c \
				bonus/free_memory_bonus.c \
				bonus/check_map_bonus.c \
				bonus/flood_fill_bonus.c \
				bonus/prepare_sprites_bonus.c \
				bonus/put_in_graphics_bonus.c \
				bonus/control_moves_bonus.c \
				bonus/initialization_bonus.c \
				bonus/moves_player_bonus.c \
				bonus/fill_map_bonus.c
		
OBJS = $(FILES:.c=.o)

OBJS_BONUS = $(FILES_BONUS:.c=.o)

all: $(NAME)
bonus: $(NAME_BONUS)

$(NAME): $(OBJS) include/so_long.h
	@echo "🚀 Compiling..."
	@make -s -C libft
	@make -s -C mlx
	@$(CC) $(CFLAGS) $(FILES) $(FLAGS_MLX) -L libft -lft -o $(NAME)
	@echo " Compilation finished! 👍"


$(NAME_BONUS): $(OBJS_BONUS) include/so_long_bonus.h
	@echo "🚀 Compiling bonus..."
	@make -s -C libft
	@make -s -C mlx
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(FLAGS_MLX) -L libft -lft -o $(NAME_BONUS)
	@echo " Bonus Compilation finished! 👍"

clean:
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)
	@make fclean -s -C libft
	@make clean -s -C mlx
	@echo " Cleaning finished! 🧹"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@echo " Deleting finished! 🗑"

upload:
	@if [ -z "$(m)" ]; then \
		echo "Error: Please provide a commit message using 'make upload m=\"Your message\"'"; \
		exit 1; \
	fi
	@git add .
	@git status
	@git commit -m "$(m)"
	@git push

norm: 
	@norminette src/*.c bonus/*.c include/*.h libft/*/*.c libft/*.h

re: fclean all

re-bonus: fclean bonus

.PHONY: all clean fclean re bonus upload norm re-bonus

