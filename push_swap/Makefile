# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 19:35:01 by jduraes-          #+#    #+#              #
#    Updated: 2023/11/06 19:35:20 by jduraes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC =	main.c utils_1.c rotate.c swap.c push.c utils_2.c utils_sort.c algo.c utils_cost.c sort.c utils_3.c sort_back.c sort_back_utils.c
OBJS =	${SRC:.c=.o}
HEADER =	push_swap.h
INCLUDE =	-I .
CFLAGS =	-Wall -Wextra -Werror
LIBFT =	libft
RM =	rm -f
CC =	cc -g

.o:.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)
	
$(NAME):	$(OBJS)
	@make bonus -C $(LIBFT) all
	$(CC) $(OBJS) -L $(LIBFT) -lft -o $(NAME)
	
all:	$(NAME)

clean:
	$(RM) $(OBJS)
	@make clean -C $(LIBFT)
	
fclean:	clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT)
	
re:	fclean all
	@make re -C $(LIBFT)
