/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 22:28:44 by sgalasso          #+#    #+#             */
/*   Updated: 2018/04/04 13:46:56 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	char	*str;
	int		i;

	if (s)
	{
		i = 0;
		if (!(str = ft_strdup(s)))
			return (0);
		while (str[i])
		{
			str[i] = f(str[i]);
			i++;
		}
		str[i] = '\0';
		return ((char *)str);
	}
	return (0);
}
