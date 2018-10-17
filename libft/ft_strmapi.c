/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 22:29:16 by sgalasso          #+#    #+#             */
/*   Updated: 2018/04/04 13:46:59 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char	*str;
	int		i;

	i = 0;
	if (s)
	{
		if (!(str = ft_strdup(s)))
			return (0);
		while (str[i])
		{
			str[i] = f(i, str[i]);
			i++;
		}
		str[i] = '\0';
		return ((char *)str);
	}
	return (0);
}
