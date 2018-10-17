/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_strat_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 13:50:09 by sgalasso          #+#    #+#             */
/*   Updated: 2018/06/03 13:53:39 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_last_pos(char **grid, t_pos *last_en_pos, char me)
{
	char	en;
	int		x;
	int		y;

	y = 0;
	en = (me == 'x') ? 'O' : 'X';
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == en)
			{
				last_en_pos->x = x;
				last_en_pos->y = y;
			}
			x++;
		}
		y++;
	}
}

int		ft_try_pos(t_map *new_map, int x, int y, char me)
{
	int i;
	int j;
	int n;
	int temp;

	i = -1;
	n = 0;
	temp = x;
	while (new_map->el[++i])
	{
		j = 0;
		x = temp;
		while (new_map->el[i][j])
		{
			if ((new_map->grid[y][x] == me || new_map->grid[y][x] ==
			me - 32) && new_map->el[i][j] == '*')
				n++;
			else if (new_map->grid[y][x] != '.' && new_map->el[i][j] == '*')
				return (0);
			j++;
			x++;
		}
		y++;
	}
	return (n = (n == 1) ? 1 : 0);
}

int		ft_calc_range(int x, int y, t_pos *last_en_pos)
{
	int a;
	int b;
	int range;

	a = last_en_pos->x - x;
	b = last_en_pos->y - y;
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	range = (ft_pow(2, a) + ft_pow(2, b)) / 2;
	return (range);
}

int		ft_get_range(char **el, int x, int y, t_pos *last_en_pos)
{
	int i;
	int j;
	int temp;
	int range;

	i = 0;
	range = -1;
	temp = x;
	while (el[i])
	{
		j = 0;
		x = temp;
		while (el[i][j])
		{
			if (el[i][j] != '.')
				if (range == -1 || (ft_calc_range(x, y, last_en_pos) < range))
					range = ft_calc_range(x, y, last_en_pos);
			j++;
			x++;
		}
		i++;
		y++;
	}
	return (range);
}
