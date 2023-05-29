/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:05:47 by sejinkim          #+#    #+#             */
/*   Updated: 2023/05/29 17:08:53 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	_num_(char *str)
{
	int	num;

	num = *str - '0';
	if ('a' <= *str)
		num += '0' - 'a' + 10;
	else if ('A' <= *str)
		num += '0' - 'A' + 10;
	return (num);
}

static int	_is_num_(char *str)
{
	if ('0' <= *str && *str <= '9')
		return (1);
	if ('a' <= *str && *str <= 'f')
		return (1);
	if ('A' <= *str && *str <= 'F')
		return (1);
	return (0);
}

int	get_color(char *str)
{
	int	color;

	color = 0;
	while (*str && *str != ',')
		str++;
	if (!*str)
		return (0xffffff);
	while (*str && *str != 'x')
		str++;
	if (*str == 'x')
		str++;
	while (_is_num_(str))
		color = color * 16 + _num_(str++);
	return (color);
}
