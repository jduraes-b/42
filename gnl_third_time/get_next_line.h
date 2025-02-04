/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 20:45:17 by jduraes-          #+#    #+#             */
/*   Updated: 2023/06/20 19:47:59 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

int		ft_strlen(char *s);
char	*fillstash(int fd, char **stash, int *end);
char	*get_line(char **stash, int end);
char	*ft_strjoin(char *s1, char *s2);
char	*clean_stash(char **stash, int start, int newstashsize);
int	analyze(char **stash, int **i);
void	firststash(char **stash, int *begin);

#endif
