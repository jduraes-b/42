/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:51:06 by jduraes-          #+#    #+#             */
/*   Updated: 2023/05/18 18:29:56 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdarg.h>

int	checktype(int i, va_list args);
int	ft_printf(const char *str, ...);
int	ft_ischar(char c);
int	ft_isstring(char *str);
int	ft_isint(int n);
char	*ft_unsigneditoa(unsigned int n);
int     ft_isu(unsigned int n);

#endif
