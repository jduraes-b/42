/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:23:32 by jduraes-          #+#    #+#             */
/*   Updated: 2023/09/21 21:09:23 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*findpath(char *cmd, char **envp)
{
	char	**pathlines;
	char	*path;
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH=", 5))
		i++;
	path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	pathlines = ft_split(path, ':');
	i = 0;
	while (pathlines[i])
	{
		path = ft_strjoin(pathlines[i], "/");
		path = ft_strjoin(path, cmd);
		if (access(path, F_OK) == 0)
		{
			doublefree(pathlines);
			return (path);
		}
		free(path);
		i++;
	}
	doublefree(pathlines);
	perror("path/cmd error");
	return (NULL);
}

void	execute(char *cmd, char **envp)
{
	char	**cmdpparam;
	char	*path;

	path = findpath(cmd, envp);
	cmdpparam = ft_split(cmd, 45);
	if (!path)
	{
		free(path);
		doublefree(cmdpparam);
		perror("path error");
		exit(EXIT_FAILURE);
	}
	if (execve(path, cmdpparam, envp) == -1)
	{
		free(path);
		doublefree(cmdpparam);
		perror("execution error");
		exit(EXIT_FAILURE);
	}
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
	{
		close(p[0]);
		dup2(f[0], STDIN_FILENO);
		dup2(p[1], STDOUT_FILENO);
		execute(argv[2], envp);
	}
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
		if (f[0] == -1 || f[1] == -1)
		{
			perror("file");
			exit(EXIT_FAILURE);
		}
		pipex(f, p, argv, envp);
	}
	else
	{
		perror("wrong number of arguments");
		exit(1);
	}
	return (0);
}
