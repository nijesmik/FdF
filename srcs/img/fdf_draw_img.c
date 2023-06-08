/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:52:42 by sejinkim          #+#    #+#             */
/*   Updated: 2023/06/09 01:12:34 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return ;
	dst = img->addr + (y * img->line_size + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_image(t_vars *vars)
{
	size_t	i;

	vars->img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.img, \
		&vars->img.bits_per_pixel, &vars->img.line_size, &vars->img.endian);
	i = 0;
	while (i < vars->map.x_size * vars->map.y_size)
	{
		draw_pixel(&vars->img, vars->map.pos[i].x, vars->map.pos[i].y, \
													vars->map.pos[i].color);
		if ((i + 1) % vars->map.x_size)
			draw_line(&vars->img, vars->map.pos[i], vars->map.pos[i + 1]);
		if (i < (vars->map.y_size - 1) * vars->map.x_size)
			draw_line(&vars->img, vars->map.pos[i], \
										vars->map.pos[i + vars->map.x_size]);
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}
