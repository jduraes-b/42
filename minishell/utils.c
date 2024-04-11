/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 20:20:24 by jduraes-          #+#    #+#             */
/*   Updated: 2024/04/11 19:58:08 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	getenv(t_shell *shell, char **envp)
{
	int	i;
	char	**env;

	i = 0;
	while(envp[i++] != NULL)
		;
	env = malloc(sizeof(char*) * (i + 1));
	i = 0;
	while (envp[i] != NULL)
		env[i] = ft_strdup(envp[i++]);
	env[i] = NULL;
}
