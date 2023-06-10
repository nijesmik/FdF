/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:46:07 by sejinkim          #+#    #+#             */
/*   Updated: 2023/06/09 00:08:20 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	x_rotation(t_map *map, double radian)
{
	size_t	i;

	i = 0;
	while (i < map->x_size * map->y_size)
	{
		map->pos[i].x = map->pos[i].x;
		map->pos[i].y = cos(radian) * map->pos[i].y \
									- sin(radian) * map->pos[i].z;
		map->pos[i].z = sin(radian) * map->pos[i].y \
									+ cos(radian) * map->pos[i].z;
		i++;
	}
}

static void	y_rotation(t_map *map, double radian)
{
	size_t	i;

	i = 0;
	while (i < map->x_size * map->y_size)
	{
		map->pos[i].z = cos(radian) * map->pos[i].z \
									- sin(radian) * map->pos[i].x;
		map->pos[i].y = map->pos[i].y;
		map->pos[i].x = sin(radian) * map->pos[i].z \
									+ cos(radian) * map->pos[i].x;
		i++;
	}
}

static void	z_rotation(t_map *map, double radian)
{
	size_t	i;

	i = 0;
	while (i < map->x_size * map->y_size)
	{
		map->pos[i].x = cos(radian) * map->pos[i].origin_x \
									- sin(radian) * map->pos[i].origin_y;
		map->pos[i].y = sin(radian) * map->pos[i].origin_x \
									+ cos(radian) * map->pos[i].origin_y;
		map->pos[i].z = map->pos[i].origin_z;
		i++;
	}
}

void	rotation(t_vars *vars)
{
	z_rotation(&vars->map, vars->tr.z_rotate);
	y_rotation(&vars->map, vars->tr.y_rotate);
	x_rotation(&vars->map, vars->tr.x_rotate);
}
