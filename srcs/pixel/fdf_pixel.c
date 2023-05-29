/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_pixel2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:58:22 by sejinkim          #+#    #+#             */
/*   Updated: 2023/05/29 17:14:14 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_max_min(t_map *map, t_trans *tr)
{
	size_t	i;
	size_t	j;

	tr->x_max = map->pos[0].x;
	tr->x_min = map->pos[0].x;
	tr->y_max = map->pos[0].y;
	tr->y_min = map->pos[0].y;
	j = 0;
	while (j < map->y_size)
	{
		i = 0;
		while (i < map->x_size)
		{
			if (tr->x_max < map->pos[j * map->x_size + i].x)
				tr->x_max = map->pos[j * map->x_size + i].x;
			if (tr->x_min > map->pos[j * map->x_size + i].x)
				tr->x_min = map->pos[j * map->x_size + i].x;
			if (tr->y_max < map->pos[j * map->x_size + i].y)
				tr->y_max = map->pos[j * map->x_size + i].y;
			if (tr->y_min > map->pos[j * map->x_size + i].y)
				tr->y_min = map->pos[j * map->x_size + i].y;
			i++;
		}
		j++;
	}
}

void	transformation(t_map *map, t_trans *tr)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < map->y_size)
	{
		i = 0;
		while (i < map->x_size)
		{
			map->pos[j * map->x_size + i].x = \
				tr->x_scale * map->pos[j * map->x_size + i].x + tr->x_shift;
			map->pos[j * map->x_size + i].y = \
				tr->y_scale * map->pos[j * map->x_size + i].y + tr->y_shift;
			i++;
		}
		j++;
	}
}

void	get_pixel(t_map *map)
{
	size_t	mid_idx;
	t_trans	tr;

	rotation(map, PI / 4, 0, PI / 4);
	get_max_min(map, &tr);
	tr.x_scale = WIDTH / (tr.x_max - tr.x_min) / 2;
	tr.y_scale = HEIGHT / (tr.y_max - tr.y_min) / 2;
	mid_idx = map->x_size * (map->y_size / 2) + map->x_size / 2;
	tr.x_shift = WIDTH / 2 - map->pos[mid_idx].x * tr.x_scale;
	tr.y_shift = HEIGHT / 2 - map->pos[mid_idx].y * tr.y_scale;
	transformation(map, &tr);
}
