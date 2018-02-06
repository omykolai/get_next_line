/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 13:49:54 by omykolai          #+#    #+#             */
/*   Updated: 2017/11/18 13:49:59 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	*get_copy(unsigned char *c, size_t size)
{
	unsigned char	*c_copy;

	if (!(c_copy = (unsigned char*)malloc(sizeof(unsigned char) * size)))
		return (NULL);
	while (--size)
		c_copy[size] = c[size];
	*c_copy = *c;
	return ((void*)c_copy);
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*first;

	if (!(first = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		first->content = NULL;
		first->content_size = 0;
	}
	else
	{
		if (!(first->content = get_copy((unsigned char*)content, content_size)))
			return (NULL);
		first->content_size = content_size;
	}
	first->next = NULL;
	return (first);
}
