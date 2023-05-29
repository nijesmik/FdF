/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:10:20 by sejinkim          #+#    #+#             */
/*   Updated: 2023/05/25 19:05:57 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_pos(t_map *map)
{
	size_t	i;
	size_t	j;

	printf("x_max:%f, x_min:%f\n", map->x_max, map->x_min);
	printf("y_max:%f, y_min:%f\n", map->y_max, map->y_min);
	j = 0;
	while (j < map->y_size)
	{
		i = 0;
		while (i < map->x_size)
		{
			printf("%d ", (int)map->pos[j * map->x_size + i++].z);
		}
		printf("\n");
		j++;
	}
}
