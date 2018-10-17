/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_el.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:59:31 by sgalasso          #+#    #+#             */
/*   Updated: 2018/06/08 14:27:30 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		ft_get_el_h(t_map *new_map)
{
	int x;
	int y;
	int start;
	int end;

	y = 0;
	start = -1;
	end = 0;
	while (new_map->bloc[y])
	{
		x = 0;
		while (new_map->bloc[y][x])
		{
			if (new_map->bloc[y][x] == '*' && start == -1)
				start = y;
			if (new_map->bloc[y][x] == '*' && y > end)
				end = y;
			x++;
		}
		y++;
	}
	new_map->e_h = end - start + 1;
	return (start);
}

int		ft_get_el_w(t_map *new_map)
{
	int x;
	int y;
	int start;
	int end;

	y = 0;
	start = -1;
	end = 0;
	while (new_map->bloc[y])
	{
		x = 0;
		while (new_map->bloc[y][x])
		{
			if (new_map->bloc[y][x] == '*' && (start == -1 || x < start))
				start = x;
			if (new_map->bloc[y][x] == '*' && x > end)
				end = x;
			x++;
		}
		y++;
	}
	new_map->e_w = end - start + 1;
	return (start);
}

int		ft_get_el(t_map *new_map, int i, int j)
{
	int k;
	int l;

	new_map->e_x = ft_get_el_w(new_map);
	new_map->e_y = ft_get_el_h(new_map);
	if (!(new_map->el = (char **)(malloc(sizeof(char *) * (new_map->e_h + 1)))))
		return (0);
	i = ft_get_el_h(new_map);
	k = 0;
	while (k < new_map->e_h)
	{
		if (!(new_map->el[k] = (char *)(malloc(sizeof(char) *
		(new_map->e_w + 1)))))
			return (0);
		j = ft_get_el_w(new_map);
		l = 0;
		while (l < new_map->e_w)
			new_map->el[k][l++] = new_map->bloc[i][j++];
		new_map->el[k++][l] = 0;
		i++;
	}
	new_map->el[k] = 0;
	return (1);
}
