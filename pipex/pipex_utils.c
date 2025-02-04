/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:03:34 by jduraes-          #+#    #+#             */
/*   Updated: 2023/09/21 19:43:47 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
