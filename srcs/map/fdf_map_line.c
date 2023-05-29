/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:38:38 by sejinkim          #+#    #+#             */
/*   Updated: 2023/05/29 19:38:29 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	_copy_(char *dst, char *src, size_t size)
{
	size_t	i;

	if (!src)
		return ;
	i = 0;
	while (src[i] && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

static void	_err_(char *str)
{
	if (str)
		free(str);
	perror("malloc error");
	exit(EXIT_FAILURE);
}

static char	*_join_(char *str, char *buf, size_t str_len, size_t buf_len)
{
	char	*ret;

	ret = malloc(sizeof(char) * (str_len + buf_len + 1));
	if (!ret)
		_err_(str);
	_copy_(ret, str, str_len + 1);
	_copy_(ret + str_len, buf, buf_len + 1);
	free(str);
	return (ret);
}

char	*map_to_line(int fd)
{
	char	buf[1024];
	char	*str;
	size_t	total;
	ssize_t	size;

	str = NULL;
	total = 0;
	size = 1024;
	while (size == 1024)
	{
		size = read(fd, buf, 1024);
		if (!size && !total)
		{
			write(2, "error : Invalid map file\n", 25);
			exit(EXIT_FAILURE);
		}
		if (size < 0)
			_err_(str);
		str = _join_(str, buf, total, size);
		total += size;
	}
	return (str);
}
