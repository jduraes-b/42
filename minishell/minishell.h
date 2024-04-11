/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:35:58 by jduraes-          #+#    #+#             */
/*   Updated: 2024/04/10 20:14:39 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef "MINISHELL_H"
# define "MINISHELL_H"

# include "../libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <signals.h>
# include <readline/history.h>
# include <readline/readline.h>

typedef struct s_shell
{
	char**	env;
	char*	line;
}	t_shell;

#endif
