/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:23:32 by jduraes-          #+#    #+#             */
/*   Updated: 2023/09/22 19:49:32 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char *cmd, char **envp)
{
	char	**cmdpparam;
	char	*path;

	cmdpparam = ft_split(cmd, 32);
	path = findpath(cmdpparam[0], envp);
	if (!path)
	{
		dup2(STDIN_FILENO, STDERR_FILENO);
		ft_printf("%s: not found", cmdpparam[0]);
		free(path);
		doublefree(cmdpparam);
		exit(127);
	}
	if (execve(path, cmdpparam, envp) == -1)
	{
		free(path);
		doublefree(cmdpparam);
		perror("execution error");
		exit(EXIT_FAILURE);
	}
}

void	child(int *f, int *p, char **argv, char **envp)
{
	if (access(argv[1], R_OK) != 0)
	{
		perror("file");
		exit(1);
	}
	close(p[0]);
	dup2(f[0], STDIN_FILENO);
	dup2(p[1], STDOUT_FILENO);
	execute(argv[2], envp);
}

void	pipex(int *f, int *p, char **argv, char **envp)
{
	int	pid;

	if (pipe(p) == -1)
		perror("pipe");
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(0);
	}
	if (pid == 0)
		child(f, p, argv, envp);
	else
	{
		waitpid(pid, NULL, 0);
		close(p[1]);
		dup2(p[0], STDIN_FILENO);
		dup2(f[1], STDOUT_FILENO);
		execute(argv[3], envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	f[2];
	int	p[2];

	if (argc == 5)
	{
		f[0] = open(argv[1], O_RDONLY, 0644);
		f[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		pipex(f, p, argv, envp);
	}
	else
	{
		perror("wrong number of arguments");
		exit(1);
	}
	return (0);
}
