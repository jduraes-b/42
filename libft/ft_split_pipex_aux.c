/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipex_aux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:52:02 by jduraes-          #+#    #+#             */
/*   Updated: 2023/10/03 20:10:21 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	quoteskip(char *s, int i)
{
	while (*s)
	{
		if (s[i] == '\'')
		{
			while (*s)
			{
				i++;	
				if (s[i] == '\'')
					return (i);
			}
		}
		else if(s[i] == '\"')
		{
			while (*s)
			{
				i++;
				if (s[i] == '\"')
					return(i);
			}
		}
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 3)
	{
		i = quoteskip(argv[1], ft_atoi(argv[2]));
		ft_printf("%i", i);
	}
	return (0);
}
