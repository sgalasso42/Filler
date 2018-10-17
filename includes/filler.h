/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:12:36 by sgalasso          #+#    #+#             */
/*   Updated: 2018/06/08 14:36:27 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>

typedef struct			s_player
{
	char		me;
	char		en;
}						t_player;

typedef struct			s_map
{
	char			**grid;
	int				g_w;
	int				g_h;
	char			**bloc;
	int				bloc_w;
	int				bloc_h;
	char			**el;
	int				e_x;
	int				e_y;
	int				e_w;
	int				e_h;
}						t_map;

typedef struct			s_pos
{
	int x;
	int y;
}						t_pos;

void					ft_free(t_map *new_map);
int						ft_get_el(t_map *new_map, int i, int j);
void					ft_last_pos(char **grid, t_pos *last_en_pos, char me);
int						ft_try_pos(t_map *new_map, int x, int y, char me);
int						ft_calc_range(int x, int y, t_pos *last_en_pos);
int						ft_get_range(char **el, int x, int y,
						t_pos *last_en_pos);
int						ft_strat_1(t_map *new_map, t_player *player,
						t_pos *next_pos);

#endif
