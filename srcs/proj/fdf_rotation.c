/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:46:07 by sejinkim          #+#    #+#             */
/*   Updated: 2023/06/21 16:43:43 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	x_rotation(t_map *map, size_t i, double radian)
{
	map->pos[i].y = cos(radian) * map->pos[i].y \
								- sin(radian) * map->pos[i].z;
	map->pos[i].z = sin(radian) * map->pos[i].y \
								+ cos(radian) * map->pos[i].z;
}

static void	y_rotation(t_map *map, size_t i, double radian)
{
	map->pos[i].z = cos(radian) * map->pos[i].z \
								- sin(radian) * map->pos[i].x;
	map->pos[i].x = sin(radian) * map->pos[i].z \
								+ cos(radian) * map->pos[i].x;
}

static void	z_rotation(t_map *map, size_t i, double radian)
{
	map->pos[i].x = cos(radian) * map->pos[i].origin_x \
								- sin(radian) * map->pos[i].origin_y;
	map->pos[i].y = sin(radian) * map->pos[i].origin_x \
								+ cos(radian) * map->pos[i].origin_y;
	map->pos[i].z = map->pos[i].origin_z;
}

void	rotation(t_vars *vars)
{
	size_t	i;

	i = 0;
	while (i < vars->map.x_size * vars->map.y_size)
	{
		z_rotation(&vars->map, i, vars->tr.z_rotate);
		y_rotation(&vars->map, i, vars->tr.y_rotate);
		x_rotation(&vars->map, i, vars->tr.x_rotate);
		i++;
	}
}
