/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:23:32 by jduraes-          #+#    #+#             */
/*   Updated: 2023/09/20 22:25:48 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*
void	child(int *f, int *fd, char **argv, char** evnp)
{
	close(fd[0]);
	dup2(f[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	execute(argv[2], envp);
}

void	parent(int *f, int *fd, char **argv, char** envp);
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(f[1], STDOUT_FILENO);
	execute(argv[3], envp);
}*/

void	pipex(int *f, char** argv, char** envp)
{
	int	pid;
	int	fd[2];

	if (pipe(fd) == -1)
		perror("pipe");
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(0);
	}
	if (pid == 0)
	{
	//	child(f, fd, argv, envp);
		close(fd[0]);
		dup2(f[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		execute(argv[2], envp);
	}
	else
	{
		waitpid(pid, NULL, 0);
	//	parent(f, fd, argv, envp);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		dup2(f[1], STDOUT_FILENO);
		execute(argv[3], envp);
	}

}

int	main(int argc, char** argv, char** envp)
{
	int	f[2];

	if (argc == 5)
	{
		f[0] = open(argv[1], O_RDONLY, 0644);
		f[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (f[0] == -1 || f[1] == -1)
		{
			perror("file");
			exit(EXIT_FAILURE);
		}
		pipex(f, argv, envp);
	}
	else
	{
		perror("wrong number of arguments");
		exit(1);
	}
	return (0);
}

