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
SRC =	main.c algo.c movements_1.c movements_2.c movements_3.c sort.c utils_analysis.c utils_analysis_2.c utils_lists.c cost.c utils_checks.c sort_utils_1.c sort_utils_2.c
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
