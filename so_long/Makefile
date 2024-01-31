# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 19:08:31 by jduraes-          #+#    #+#              #
#    Updated: 2024/01/24 20:25:34 by jduraes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = src/main.c src/mapread.c src/mapread_utils.c src/mlxstart.c src/movement.c
OBJS = $(SRC:.c=.o)
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11 -lm
LIBMLX = minilibx-linux/libmlx.a

$(NAME): $(OBJS)
	@make bonus -C libft all
	$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) -L libft -lft $(LIBMLX) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	@make clean -C libft

fclean:	clean
	$(RM) $(NAME)
	@make fclean -C libft

re:	fclean all
	@make re -C libft

.phony: all clean fclean re
