/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:09:28 by sejinkim          #+#    #+#             */
/*   Updated: 2023/05/29 18:12:00 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>

# define WIDTH 1920
# define HEIGHT 1080
# define PI 3.14159265

typedef struct s_mlx_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}	t_img;

typedef struct s_coordinate
{
	double	origin_x;
	double	origin_y;
	double	origin_z;
	double	x;
	double	y;
	double	z;
	int		color;
}	t_pos;

typedef struct s_line
{
	int	w;
	int	h;
	int	f;
	int	d_f[2];
	int	pos[2];
	int	d_pos[2];
	int	end;
	int	idx;
}	t_line;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_transform
{
	double	x_max;
	double	x_min;
	double	x_scale;
	double	x_shift;
	double	y_max;
	double	y_min;
	double	y_scale;
	double	y_shift;
}	t_trans;

typedef struct s_map
{
	size_t				x_size;
	size_t				y_size;
	struct s_coordinate	*pos;
}	t_map;

void	get_map_info(char *file, t_map *map);
char	*map_to_line(int fd);
int		get_color(char *str);
void	init_pos(t_map *map, size_t x, size_t y, char *str);
size_t	get_split_size(char const *s, char c);
char	**ft_split(char const *s, char c, size_t size);
char	**free_ptr(char **ptr);
void	rotation(t_map *map, double x_radian, double y_radian, double z_radian);
void	get_pixel(t_map *map);
void	get_mlx(t_map *map);
void	draw_pixel(t_img *img, int x, int y, int color);
void	draw_line(t_img *img, t_pos start, t_pos end);
int		key_hook(int keycode, t_mlx *mlx);

#endif