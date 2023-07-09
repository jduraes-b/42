/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:22:30 by jduraes-          #+#    #+#             */
/*   Updated: 2023/07/09 22:34:42 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**findpaths(char **envp)
{
	int	i;
	char	**paths;
	char	*actualpath;

	i = 0;
	while(!ft_strnstr(envp[i], "PATH=", 5))
		i++;
	actualpath = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	paths = ft_split(actualpath + 5, ':');
	return (paths);
}

char	*getcmdpath(char **paths, char *cmd, char **envp)
{
	char	*path;
	int	i;

	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(envp[i], "/");
		path = ft_strjoin(path, cmd);
		if (access(path, F_OK) == 0)
		{
			doublefree(paths);
			return (path);
		}
		free(path);
		i++;
	}
	doublefree(paths);
	ft_printf("Error\n");
	return (NULL);
}

void	doublefree(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	execute(char *cmd, char **envp)
{
	char	*cmdpath;
	char	**cmdprep;
	char	**paths;

	paths = findpaths(envp);
	cmdpath = getcmdpath(paths, cmd, envp);
	cmdprep = ft_split(cmd, 45);
	if (!cmdpath)
	{
		free(cmdpath);
		doublefree(cmdprep);
		perror("path");
		exit(EXIT_FAILURE);
	}
	if (execve(cmdpath, cmdprep, envp) == -1)
	{
		doublefree(cmdprep);
		free(cmdpath);
		perror("execution");
		exit(EXIT_FAILURE);
	}
}
