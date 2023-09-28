# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkayis <tkayis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 18:01:39 by tkayis            #+#    #+#              #
#    Updated: 2023/09/28 19:21:03 by tkayis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS				= main.c create_window.c \
					./get_next_line/get_next_line.c \
					./get_next_line/get_next_line_utils.c
	
OBJS				= $(SRCS:.c=.o)
	
CC					= gcc
RM					= rm -rf
CFLAGS				= -Wall -Wextra -Werror 
MLX_DIR				= ./mlx
GET_NEXT_LINE_DIR	= ./get_next_line
LIBFT_DIR			= ./libft
LIBFT				= ./libft/libft.a
PRINTF_DIR			= ./printf
PRINTF				= ./printf/libftprintf.a


NAME			= test

%.o: %.c
				make -C $(PRINTF_DIR)
				make -C $(LIBFT_DIR)
				make -C $(MLX_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJS)
				$(CC) $(OBJS) $(LIBFT) $(PRINTF) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all:			$(NAME)

clean:			
				make clean -C $(MLX_DIR)
				make clean -C $(LIBFT_DIR) 
				make clean -C $(PRINTF_DIR) 
				$(RM) $(OBJS)

fclean:			clean
				make fclean -C $(LIBFT_DIR) 
				make fclean -C $(PRINTF_DIR) 
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
