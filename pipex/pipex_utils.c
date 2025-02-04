/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:22:30 by jduraes-          #+#    #+#             */
/*   Updated: 2023/07/06 20:55:41 by jduraes-         ###   ########.fr       */
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
	actualpath = ft_substr(envp[i], 5, ft_strlen(envp[i]);
	paths = ft_split(actualpath + 5, ":");
	return (paths);
}

char	*getcmdpath(char **paths, char *cmd)
{
	char	*path
	int	i;

	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(envp[i], "/");
		path = ft_strjoin(path, cmd);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	ft_printf("Error\n");
	return (NULL);
}
/*
void	execute(char **paths, char *cmd)
{

}*/
