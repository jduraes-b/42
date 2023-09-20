/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:59:55 by jduraes-          #+#    #+#             */
/*   Updated: 2023/07/09 22:31:01 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child(int *f, int *fd, char **argv, char **envp)
{
	dup2(fd[1], STDOUT_FILENO);
	dup2(f[0], STDIN_FILENO);
	close(fd[0]);
	execute(argv[2], envp);
}

static void	child2(int *f, int *fd, char **argv, char **envp)
{
	dup2(fd[0], STDIN_FILENO);
	dup2(f[1], STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);	
}
static void	pipex(int *f, char **argv, char **envp)
{
	int	fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid1 = fork();
	pid2 = fork();
	if (pid1 == -1 || pid2 == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid1 == 0)
		child(f, fd, argv, envp);
	waitpid(pid1, NULL, 0);
	if (pid2 == 0)
		child2(f, fd, argv, envp);
	waitpid(pid2, NULL, 0);
	if (pid1 > 0 && pid2 > 0)
	{
		close(fd[0]);
		close(fd[1]);
	}
}

int	main(int argc, char *argv[], char **envp)
{
	int	f[2];
//	char	**realpaths;

	if (argc == 5)
	{
		f[0] = open(argv[1], O_RDONLY, 0777);
		f[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
		if (f[0] == -1 || f[1] == -1)
		{
			perror("file");
			exit(EXIT_FAILURE);
		}
		//realpaths = findpaths(char **envp);
		pipex(f, argv, envp);
	}
	else
	{
		perror("wrong number of arguments");
		exit(1);
	}
	return (0);
}
