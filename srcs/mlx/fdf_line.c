/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:44:01 by sejinkim          #+#    #+#             */
/*   Updated: 2023/05/29 15:55:24 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	_slope_(t_line *l, int y)
{
	int	tmp;

	if (l->h < l->w)
		return ;
	tmp = l->w;
	l->w = l->h;
	l->h = tmp;
	l->end = y;
	l->idx = 1;
}

static void	_init_(t_pos start, t_pos end, t_line *l)
{
	l->end = (int)end.x;
	l->idx = 0;
	l->pos[0] = (int)start.x;
	l->pos[1] = (int)start.y;
	l->d_pos[0] = 1;
	l->d_pos[1] = 1;
	if (end.x < start.x)
		l->d_pos[0] = -1;
	if (end.y < start.y)
		l->d_pos[1] = -1;
	l->w = (int)fabs(end.x - start.x);
	l->h = (int)fabs(end.y - start.y);
	_slope_(l, end.y);
	l->f = 2 * l->h - l->w;
	l->d_f[1] = 2 * l->h;
	l->d_f[0] = 2 * (l->h - l->w);
}

static int	_color_(double ratio, int start_color, int end_color)
{
	int		r;
	int		g;
	int		b;

	r = (int)(((start_color >> 16) & 0xff) * ratio \
					+ ((end_color >> 16) & 0xff) * (1.0 - ratio));
	g = (int)(((start_color >> 8) & 0xff) * ratio \
					+ ((end_color >> 8) & 0xff) * (1.0 - ratio));
	b = (int)((start_color & 0xff) * ratio + (end_color & 0xff) * (1 - ratio));
	return ((r << 16) | (g << 8) | b);
}

void	draw_line(t_img *img, t_pos start, t_pos end)
{
	t_line	l;
	double	ratio;

	_init_(start, end, &l);
	while (l.pos[l.idx] != l.end)
	{
		l.pos[l.idx] += l.d_pos[l.idx];
		if (l.f < 0)
			l.f += l.d_f[1];
		else
		{
			l.f += l.d_f[0];
			l.pos[1 - l.idx] += l.d_pos[1 - l.idx];
		}
		ratio = fabs((double)(l.end - l.pos[l.idx])) / l.w;
		draw_pixel(img, l.pos[0], l.pos[1], \
						_color_(ratio, start.color, end.color));
	}
}
