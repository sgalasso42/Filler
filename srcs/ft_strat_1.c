/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strat_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 19:22:31 by sgalasso          #+#    #+#             */
/*   Updated: 2018/06/08 14:27:35 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		ft_find_closest_parsing(t_map *new_map, t_pos *last_en_pos,
		t_pos *temp, t_player *player)
{
	char	**grid;
	char	**el;
	int		range;
	int		c_xy[2];

	grid = new_map->grid;
	el = new_map->el;
	range = -1;
	c_xy[1] = -1;
	while (grid[++c_xy[1]])
	{
		c_xy[0] = -1;
		while (grid[c_xy[1]][++c_xy[0]])
			if ((c_xy[0] < new_map->g_w - new_map->e_w && c_xy[1] < new_map->g_h
	- new_map->e_h) && (ft_try_pos(new_map, c_xy[0], c_xy[1], player->me)) &&
	((ft_get_range(el, c_xy[0], c_xy[1], last_en_pos) < range) || range == -1))
			{
				range = ft_get_range(el, c_xy[0], c_xy[1], last_en_pos);
				temp->x = c_xy[0];
				temp->y = c_xy[1];
			}
	}
	return (range);
}

int		ft_find_closest(t_map *new_map, t_pos *last_en_pos,
		t_pos *next_pos, t_player *player)
{
	t_pos	temp;
	int		range;

	range = -1;
	temp.x = 0;
	temp.y = 0;
	range = ft_find_closest_parsing(new_map, last_en_pos, &temp, player);
	if (range == -1)
		return (0);
	next_pos->x = temp.x;
	next_pos->y = temp.y;
	return (1);
}

int		ft_strat_1(t_map *new_map, t_player *player, t_pos *next_pos)
{
	t_pos	last_en_pos;

	ft_last_pos(new_map->grid, &last_en_pos, player->me);
	if (!(ft_find_closest(new_map, &last_en_pos, next_pos, player)))
		return (0);
	next_pos->x = next_pos->x - new_map->e_x;
	next_pos->y = next_pos->y - new_map->e_y;
	return (1);
}
