SRCS				= main.c create_window.c render_map.c error_handling.c \
					player_move.c put_components.c update_image.c \
					./get_next_line/get_next_line.c map_checkers.c \
					./get_next_line/get_next_line_utils.c game_checkers.c
	
OBJS				= $(SRCS:.c=.o)
	
CC					= cc
RM					= rm -rf
CFLAGS				= -Wall -Wextra -Werror
MLX_DIR				= ./mlx
LIBFT_DIR			= ./libft
LIBFT				= ./libft/libft.a
PRINTF_DIR			= ./printf
PRINTF				= ./printf/libftprintf.a


NAME			= so_long

%.o: %.c
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJS)
				@make -C $(PRINTF_DIR)
				@make -C $(LIBFT_DIR)
				@make -C $(MLX_DIR)
				@$(CC) $(OBJS) $(LIBFT) $(PRINTF) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all:			$(NAME)

clean:			
				@make clean -C $(MLX_DIR)
				@make clean -C $(LIBFT_DIR) 
				@make clean -C $(PRINTF_DIR) 
				$(RM) $(OBJS)

fclean:			clean
				@make fclean -C $(LIBFT_DIR) 
				@make fclean -C $(PRINTF_DIR) 
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
