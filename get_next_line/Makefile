# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 19:54:26 by jduraes-          #+#    #+#              #
#    Updated: 2023/06/06 20:04:53 by jduraes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	get_next_line.a
FTS =
SRC =	$(FTS)
OBJS =	$(SRC:.c=.o)
HEADER =	get_next_line.h
INCLUDE =	-I .
CFLAGS =	-Wall -Wextra -Werror
LIBFT =	libft
LIBFTPATH =	$(LIBFT)/libft.a
RM =	rm -f
CC =	cc -g
.o:.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)
$(NAME):	$(OBJS)
	make bonus -C $(LIBFT) all
	cp $(LIBFTPATH) $(NAME)
	ar rcs $(NAME) $(OBJS) $(HEADER)
all:	$(NAME)
clean:
	$(RM) $(OBJS)
fclean:	clean
	$(RM) $(NAME)
re:	fclean all
