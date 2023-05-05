# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 17:31:07 by jduraes-          #+#    #+#              #
#    Updated: 2023/05/05 17:40:02 by jduraes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a
PART1 =	ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memset.c ft_strlen.c ft_tolower.c ft_toupper.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_atoi.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strncmp.c ft_strnstr.c ft_strrchr.c
PART2 =	ft_itoa.c ft_split.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_strmapi.c
SRC =	${PART1} ${PART2}
OBJS =	${SRC:.c=.o}
HEADER =	libft.h
INCLUDE =	-I .
CC =	cc -g
RM =	rm -f
CFLAGS =	-Wall -Wextra -Werror
%.o:%.c
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}
${NAME}:	${OBJS}
	ar rcs ${NAME} ${OBJS} ${HEADER}
all:	${NAME}
clean:	
	${RM} ${OBJS}
fclean:	clean
	${RM} ${NAME}
re:	fclean all
