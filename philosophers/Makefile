# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 17:28:43 by jduraes-          #+#    #+#              #
#    Updated: 2024/04/04 17:29:59 by jduraes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers
SRC =	main.c utils.c
OBJS =	${SRC:.c=.o}
HEADER =	philo.h
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
