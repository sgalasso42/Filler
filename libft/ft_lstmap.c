/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:52:02 by sgalasso          #+#    #+#             */
/*   Updated: 2018/04/19 23:31:13 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*first;
	t_list	*el;

	temp = 0;
	if (!lst)
		return (0);
	if (!(el = (t_list *)(malloc(sizeof(t_list)))))
		return (0);
	el = f(lst);
	temp = el;
	first = el;
	lst = lst->next;
	while (lst)
	{
		if (!(el = (t_list *)(malloc(sizeof(t_list)))))
			return (0);
		el = f(lst);
		temp->next = el;
		temp = el;
		lst = lst->next;
	}
	return (first);
}
