/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transformation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 01:09:54 by sejinkim          #+#    #+#             */
/*   Updated: 2023/06/09 01:10:30 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	transformation(t_vars *vars)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < vars->map.y_size)
	{
		i = 0;
		while (i < vars->map.x_size)
		{
			vars->map.pos[j * vars->map.x_size + i].x = vars->tr.scale \
				* vars->map.pos[j * vars->map.x_size + i].x + vars->tr.x_shift;
			vars->map.pos[j * vars->map.x_size + i].y = vars->tr.scale \
				* vars->map.pos[j * vars->map.x_size + i].y + vars->tr.y_shift;
			i++;
		}
		j++;
	}
}
