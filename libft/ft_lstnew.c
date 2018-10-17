/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:10:11 by sgalasso          #+#    #+#             */
/*   Updated: 2018/04/13 00:29:27 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list *)(malloc(sizeof(t_list)))))
		return (0);
	if (content)
	{
		if (!(new->content = (void *)malloc(sizeof(t_list) * content_size)))
			return (0);
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	else
	{
		new->content = 0;
		new->content_size = 0;
	}
	new->next = 0;
	return (new);
}
