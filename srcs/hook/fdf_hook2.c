/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 01:16:18 by sejinkim          #+#    #+#             */
/*   Updated: 2023/06/27 11:56:34 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_hook.h"

static void	_new_image_(t_vars *vars)
{
	rotation(vars);
	transformation(vars);
	mlx_destroy_image(vars->mlx, vars->img.img);
	draw_image(vars);
}

void	rotate(int keycode, t_vars *vars)
{
	if (keycode == KEY_W)
		vars->tr.x_rotate += 0.01;
	else if (keycode == KEY_S)
		vars->tr.x_rotate -= 0.01;
	else if (keycode == KEY_X)
		vars->tr.y_rotate += 0.01;
	else if (keycode == KEY_Z)
		vars->tr.y_rotate -= 0.01;
	else if (keycode == KEY_A)
		vars->tr.z_rotate += 0.01;
	else if (keycode == KEY_D)
		vars->tr.z_rotate -= 0.01;
	_new_image_(vars);
}

void	translate(int keycode, t_vars *v)
{
	if (keycode == KEY_M)
	{
		v->tr.x_shift += WIDTH / 2 - v->map.pos[v->tr.mid_idx].x;
		v->tr.y_shift += HEIGHT / 2 - v->map.pos[v->tr.mid_idx].y;
	}
	else if (keycode == KEY_LEFT)
		v->tr.x_shift -= WIDTH / 500 + 1 + v->tr.scale / 5;
	else if (keycode == KEY_RIGHT)
		v->tr.x_shift += WIDTH / 500 + 1 + v->tr.scale / 5;
	else if (keycode == KEY_DOWN)
		v->tr.y_shift += HEIGHT / 500 + 1 + v->tr.scale / 5;
	else if (keycode == KEY_UP)
		v->tr.y_shift -= HEIGHT / 500 + 1 + v->tr.scale / 5;
	_new_image_(v);
}

void	zoom(int keycode, t_vars *vars)
{
	double	d_scale;

	d_scale = vars->tr.scale * 0.1;
	if (d_scale < 0.1)
		d_scale = 0.1;
	if (keycode == KEY_PLUS)
		vars->tr.scale += d_scale;
	else if (vars->tr.scale < d_scale)
		return ;
	else
		vars->tr.scale -= d_scale;
	_new_image_(vars);
}
