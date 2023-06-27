/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:58:22 by sejinkim          #+#    #+#             */
/*   Updated: 2023/06/27 11:56:49 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	_x_scale_(t_map *map)
{
	double	x_max;
	double	x_min;
	size_t	i;
	size_t	j;

	x_max = map->pos[0].x;
	x_min = map->pos[0].x;
	j = 0;
	while (j < map->y_size)
	{
		i = 0;
		while (i < map->x_size)
		{
			if (x_max < map->pos[j * map->x_size + i].x)
				x_max = map->pos[j * map->x_size + i].x;
			if (x_min > map->pos[j * map->x_size + i].x)
				x_min = map->pos[j * map->x_size + i].x;
			i++;
		}
		j++;
	}
	return (WIDTH / (x_max - x_min) / 2);
}

double	_y_scale_(t_map *map)
{
	double	y_max;
	double	y_min;
	size_t	i;
	size_t	j;

	y_max = map->pos[0].y;
	y_min = map->pos[0].y;
	j = 0;
	while (j < map->y_size)
	{
		i = 0;
		while (i < map->x_size)
		{
			if (y_max < map->pos[j * map->x_size + i].y)
				y_max = map->pos[j * map->x_size + i].y;
			if (y_min > map->pos[j * map->x_size + i].y)
				y_min = map->pos[j * map->x_size + i].y;
			i++;
		}
		j++;
	}
	return (HEIGHT / (y_max - y_min) / 2);
}

void	projection(t_vars *v, double x_rad, double y_rad, double z_rad)
{
	double	tmp_scale;

	v->tr.x_rotate = x_rad;
	v->tr.y_rotate = y_rad;
	v->tr.z_rotate = z_rad;
	rotation(v);
	v->tr.scale = _x_scale_(&v->map);
	tmp_scale = _y_scale_(&v->map);
	if (v->tr.scale > tmp_scale)
		v->tr.scale = tmp_scale;
	v->tr.mid_idx = v->map.x_size * (v->map.y_size / 2) + v->map.x_size / 2;
	v->tr.x_shift = WIDTH / 2 - v->map.pos[v->tr.mid_idx].x * v->tr.scale;
	v->tr.y_shift = HEIGHT / 2 - v->map.pos[v->tr.mid_idx].y * v->tr.scale;
	transformation(v);
	draw_image(v);
}
