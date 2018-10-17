/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 22:34:39 by sgalasso          #+#    #+#             */
/*   Updated: 2018/04/28 00:01:32 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *str, char c)
{
	int		i;
	int		start;
	int		end;
	int		index;
	char	**dest;

	i = 0;
	index = 0;
	if (!str || !(dest = (char **)(malloc(sizeof(char *) *
						(ft_nbwords((char *)str, c) + 1)))))
		return (0);
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		start = i;
		while (str[i] && str[i] != c)
			i++;
		end = i;
		if (end > start)
			if (!(dest[index++] = ft_strsub(str, start, end - start)))
				return (0);
	}
	dest[index] = 0;
	return (dest);
}
