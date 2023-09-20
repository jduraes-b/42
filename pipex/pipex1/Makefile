# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/28 19:48:52 by jduraes-          #+#    #+#              #
#    Updated: 2023/06/28 19:58:38 by jduraes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
OUT = pipex
SRC =	pipex.c pipex_utils.c
OBJS =	${SRC:.c=.o}
HEADER =	pipex.h
INCLUDE =	-I .
CFLAGS =	-Wall -Wextra -Werror
LIBFT =	libft
RM =	rm -f
CC =	cc -g

.o:.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)
	
$(OUT):	$(OBJS)
	make bonus -C $(LIBFT) all
	$(CC) $(OBJS) -L $(LIBFT) -lft -o $(OUT)
	
all:	$(OUT)

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT)
	
fclean:	clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)
	
re:	fclean all
	make re -C $(LIBFT)

.PHONY: all clean fclean re
