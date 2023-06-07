/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:16:00 by sejinkim          #+#    #+#             */
/*   Updated: 2023/06/07 21:19:07 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	_pos_z_(char *str)
{
	double	sign;
	double	num;

	sign = 1;
	num = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
		num = num * 10 + *str++ - '0';
	if (!*str || *str == ',')
		return (num * sign);
	write(2, "error : invalid map file\n", 25);
	exit(EXIT_FAILURE);
}

void	init_pos(t_map *map, size_t x, size_t y, char *str)
{
	double	z;
	size_t	idx;

	idx = y * map->x_size + x;
	map->pos[idx].origin_x = (double)x;
	map->pos[idx].origin_y = (double)y;
	z = _pos_z_(str);
	map->pos[idx].origin_z = z;
	map->pos[idx].color = get_color(str);
}
