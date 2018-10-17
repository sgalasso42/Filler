/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:21:36 by sgalasso          #+#    #+#             */
/*   Updated: 2018/06/08 14:30:12 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_free(t_map *new_map)
{
	int		index;

	index = 0;
	while (new_map->grid[index])
		free(new_map->grid[index++]);
	free(new_map->grid);
	index = 0;
	while (new_map->bloc[index])
		free(new_map->bloc[index++]);
	free(new_map->bloc);
	index = 0;
	while (new_map->el[index])
		free(new_map->el[index++]);
	free(new_map->el);
}
