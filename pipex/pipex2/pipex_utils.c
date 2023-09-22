/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:29:04 by jduraes-          #+#    #+#             */
/*   Updated: 2023/09/22 19:42:36 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*findpath(char *cmd, char **envp)
{
	char	**pathlines;
	char	*path;
	char	*temp;
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH=", 5))
		i++;
	path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	pathlines = ft_split(path, ':');
	free(path);
	i = 0;
	while (pathlines[i])
	{
		temp = ft_strjoin(pathlines[i], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path, F_OK) == 0)
		{
			doublefree(pathlines);
			return (path);
		}
		free(path);
		i++;
	}
	doublefree(pathlines);
	return (NULL);
}
