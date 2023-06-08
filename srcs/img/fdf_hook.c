/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:50:11 by sejinkim          #+#    #+#             */
/*   Updated: 2023/06/09 10:17:41 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_hook.h"

int	destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void	project(int keycode, t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	if (keycode == KEY_1)
		projection(vars, PI / 4, 0, PI / 4);
	else if (keycode == KEY_2)
		projection(vars, PI / 4, 0, -PI / 4);
	else if (keycode == KEY_3)
		projection(vars, 0, 0, 0);
	else if (keycode == KEY_4)
		projection(vars, PI / 2, 0, 0);
}

int	key_event(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		destroy(vars);
	else if (KEY_1 <= keycode && keycode <= KEY_4)
		project(keycode, vars);
	else if (KEY_A <= keycode && keycode <= KEY_W)
		rotate(keycode, vars);
	else if (keycode == KEY_M || (KEY_LEFT <= keycode && keycode <= KEY_UP))
		translate(keycode, vars);
	else if (KEY_MINUS == keycode || keycode == KEY_PLUS)
		zoom(keycode, vars);
	return (0);
}

void	mlx_hooks(t_vars *vars)
{
	mlx_hook(vars->win, KEY_PRESS, 0, key_event, vars);
	mlx_hook(vars->win, KEY_RELEASE, 0, key_event, vars);
	mlx_hook(vars->win, DESTROY_NOTIFY, 0, destroy, vars);
}
