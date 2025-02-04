/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:00:49 by jduraes-          #+#    #+#             */
/*   Updated: 2023/05/08 18:12:00 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *elem;

	if ((elem = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}

