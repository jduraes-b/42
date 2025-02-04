# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 20:32:32 by jduraes-          #+#    #+#              #
#    Updated: 2023/09/14 18:26:58 by jduraes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a
FTS =	auxft.c ft_printf.c ft_isu.c auxft2.c auxft3.c
SRC =	${FTS}
OBJS =	$(SRC:.c=.o)
HEADER =	ft_printf.h
INCLUDE =	-I .
CFLAGS =	-Wall -Wextra -Werror
LIBFT =	libft
LIBFTPATH =	$(LIBFT)/libft.a
RM =	rm -f
CC =	cc -g

all:	${NAME}

%.o:%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)
${NAME}:	${OBJS}
	make bonus -C $(LIBFT) all
	cp $(LIBFTPATH) $(NAME)
	ar rcs ${NAME} ${OBJS} ${HEADER}
clean:
	${RM} ${OBJS}
fclean:	clean
	${RM} ${NAME}
re:	fclean all
.PHONY: all clean fclean re
