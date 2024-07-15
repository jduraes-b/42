# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 20:48:16 by jduraes-          #+#    #+#              #
#    Updated: 2024/07/15 21:01:10 by jduraes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
SRC = src/main.c
OBJS = $(SRC:.c=.o)
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11 -lm
LIBMLX = minilibx-linux/libmlx.a

$(NAME): $(OBJS)
	@make -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) -L libft -lft $(LIBMLX) -o $(NAME)
	
clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	@make clean -C libft

fclean:	clean
	$(RM) $(NAME) $(BONUS_OBJS)
	@make fclean -C libft

re: fclean all
	make re -C libft

.phony: clean fclean re