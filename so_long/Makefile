# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 19:08:31 by jduraes-          #+#    #+#              #
#    Updated: 2024/01/22 19:17:58 by jduraes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = 
OBJS = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
IFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11 -lm
LIBMLX = minilibx-linux/libmlx.a

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) $(LIBMLX) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.phony: all clean fclean re
