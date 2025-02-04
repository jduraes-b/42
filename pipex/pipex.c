/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:59:55 by jduraes-          #+#    #+#             */
/*   Updated: 2023/06/29 21:02:34 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int f1, int f2, argv, envp)
{
	int	fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		dup2(f1, STDIN_FILENO);
		close(fd[0]);
		child_process(f1, f2, argv, envp);
	}
	else
	{
		dup2(fd[O], STDIN_FILENO);
		dup2(f2, STDOUT_FILENO);
		close(fd[1]);
		parent_process(f1, f2, argv, envp);
	}
}


int	main(int argc, char *argv[], char **envp)
{
	int	f1;
	int	f2;
	char	*envpath;

	f1 = open(argv[1], O_RDONLY, 0777);
	f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (f1 == -1 || f2 == -1)
		return (-1);
	envpath = findpath(char **envp);
	pipex(f1, f2, argv, envp);
	return (0);
}
