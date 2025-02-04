/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:22:30 by jduraes-          #+#    #+#             */
/*   Updated: 2023/06/28 22:00:06 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*findepath(char	**envp)
{
	char	*paths;

	while(!ft_strnstr(envp[i], "PATH=", 5))
		i++;
	paths = ft_split(envp[i], ":");
	
}

void	execute(char *cmd, char **envp)
{
	char	**command;
	char	*pathline;

	pathline = ft_substr(envp, );

}
