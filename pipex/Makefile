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

NAME =	pipex.a
FTS =	
SRC =	$(FTS)
OBJS =	$(SRC:.c=.o)
HEADER =	pipex.h
INCLUDE =	-I .
CFLAGS =	-Wall -Wextra -Werror
LIBFT =	libft
LIBFTPATH =	$(LIBFT)/libft.a
RM =	rm -f
CC =	cc -g
%.o:%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -g $(<:.c=.o)
$(NAME):	$(OBJS)
	make bonus -C $(LIBFT) all
	cp $(LIBFTPATH) $(NAME)
	ar rcs $(NAME) $(OBJS) $(HEADER)
all:	$(NAME)
clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT)
fclean:	clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)
re:	fclean all
	make re -C $(LIBFT)

.PHONY: all clean fclean re
