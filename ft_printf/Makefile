# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 20:32:32 by jduraes-          #+#    #+#              #
#    Updated: 2023/05/18 19:09:41 by jduraes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a
FTS =	auxft.c ft_printf.c ft_isu.c
SRC =	${FTS}
OBJS =	$(SRC:.c=.o)
HEADER =	ft_printf.h
INCLUDE =	-I .
CFLAGS =	-Wall -Wextra -Werror
LIBFT =	libft
LIBFTPATH =	$(LIBFT)/libft.a
RM =	rm -f
CC =	cc -g
%.o:%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)
${NAME}:	${OBJS}
	make bonus -C $(LIBFT) all
	cp $(LIBFTPATH) $(NAME)
	ar rcs ${NAME} ${OBJS} ${HEADER}
all:	${NAME}
clean:
	${RM} ${OBJS}
fclean:	clean
	${RM} ${NAME}
re:	fclean all
