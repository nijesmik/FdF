/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:52:42 by sejinkim          #+#    #+#             */
/*   Updated: 2023/05/29 15:09:58 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_size + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_image(t_map *map, t_img *img)
{
	size_t	i;

	i = 0;
	while (i < map->x_size * map->y_size)
	{
		draw_pixel(img, map->pos[i].x, map->pos[i].y, map->pos[i].color);
		if ((i + 1) % map->x_size)
			draw_line(img, map->pos[i], map->pos[i + 1]);
		if (i < (map->y_size - 1) * map->x_size)
			draw_line(img, map->pos[i], map->pos[i + map->x_size]);
		i++;
	}
}

void	get_mlx(t_map *map)
{
	t_mlx	mlx;
	t_img	img;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "fdf");
	img.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
									&img.line_size, &img.endian);
	draw_image(map, &img);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_loop(mlx.mlx);
}
