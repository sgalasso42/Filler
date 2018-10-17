/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 19:10:10 by sgalasso          #+#    #+#             */
/*   Updated: 2018/06/25 13:50:04 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int		ft_first_parse(char *line, t_player *player)
{
	if (line[10] != '1' && line[10] != '2')
		return (0);
	player->me = (line[10] == '1') ? 'o' : 'x';
	player->en = (line[10] == '2') ? 'x' : 'o';
	return (1);
}

void	ft_display(t_pos *next_pos, t_map *new_map)
{
	ft_putnbr(next_pos->y);
	ft_putchar(' ');
	ft_putnbr(next_pos->x);
	ft_putchar('\n');
	ft_free(new_map);
}

int		ft_parse_grid(t_map *new_map, char **line)
{
	int	index;

	if (!(new_map->g_h = ft_atoi(*line + 8)) ||
	(!(new_map->g_w = ft_atoi(*line + 8 + ft_nbrlen(new_map->g_h) + 1))))
		return (0);
	if (!(new_map->grid = (char **)(malloc(sizeof(char *) *
	(new_map->g_h + 1)))))
		return (0);
	index = 0;
	free(*line);
	get_next_line(0, line);
	while (index < new_map->g_h)
	{
		free(*line);
		get_next_line(0, line);
		if (!(new_map->grid[index] = ft_strnew(new_map->g_w + 1)))
			return (0);
		ft_strcat(new_map->grid[index], *line + 4);
		if ((int)ft_strlen(new_map->grid[index++]) != new_map->g_w)
			return (0);
	}
	free(*line);
	new_map->grid[index] = 0;
	return ((index != new_map->g_h) ? 0 : 1);
}

int		ft_parse_bloc(t_map *new_map, char **line)
{
	int		index;

	get_next_line(0, line);
	if (!(new_map->bloc_h = ft_atoi(*line + 6)) ||
	(!(new_map->bloc_w = ft_atoi(*line + 6 + ft_nbrlen(new_map->bloc_h) + 1))))
		return (0);
	if (!(new_map->bloc = (char **)(malloc(sizeof(char *) *
	(new_map->bloc_h + 1)))))
		return (0);
	index = 0;
	while (index < new_map->bloc_h)
	{
		free(*line);
		get_next_line(0, line);
		if (!(new_map->bloc[index] = ft_strnew(new_map->bloc_w + 1)))
			return (0);
		ft_strcat(new_map->bloc[index], *line);
		if ((int)ft_strlen(new_map->bloc[index++]) != new_map->bloc_w)
			return (0);
	}
	new_map->bloc[index] = 0;
	return ((index != new_map->bloc_h) ? 0 : 1);
}

int		main(void)
{
	t_player			player;
	t_map				new_map;
	t_pos				next_pos;
	char				*line;

	get_next_line(0, &line);
	if (!(ft_first_parse(line, &player)))
		return (0);
	free(line);
	while (1)
	{
		if (get_next_line(0, &line) > 0)
		{
			if (!(ft_parse_grid(&new_map, &line)) ||
			!(ft_parse_bloc(&new_map, &line)) ||
			!(ft_get_el(&new_map, 0, 0)) ||
			!(ft_strat_1(&new_map, &player, &next_pos)))
				break ;
			ft_display(&next_pos, &new_map);
		}
		free(line);
	}
	ft_free(&new_map);
	free(line);
	return (0);
}
