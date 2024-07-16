/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:29:27 by jduraes-          #+#    #+#             */
/*   Updated: 2024/07/16 20:27:38 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_perror(char *str, int fd)
{
    ft_putstr_fd("Error: ", fd);
    ft_putstr_fd(str, fd);
    ft_putstr_fd("\n", fd);
    exit(EXIT_FAILURE);
}