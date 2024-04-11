/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:35:28 by jduraes-          #+#    #+#             */
/*   Updated: 2024/04/03 20:59:03 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*findpath(char *cmd, char **envp)
{
	int		i;

	i = -1;
	while (envp[++i] && !ft_strnstr(envp[i], "PWD=", 4))
		;
	return (envp[i] + 4);
}

static int	goahead(char *path)
{
	if (access(path, F_OK) == 0)
		return (0);
	return (1);
}

static void	casenotbase(char *path, char** envp)
{
	char	*newpwd;
	char	*oldpwd;

	oldpwd = *findpath(path + 3, envp);
	oldpwd = gnl_strjoin(oldpwd, "/");
	newpwd = gnl_strjoin(oldpwd, path);
	if (goahead(newpwd))
		chdir(newpwd);
	free(newpwd);
}

int	cd(char *fullcmd, char** envp)
{
	if (fullcmd[3] == '\')
	{
		if(goahead(fullcmd + 3))
			chdir(fullcmd + 3);
	}
	else
		casenotbase(fullcmd, envp);
}
