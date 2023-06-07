/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:24:33 by sejinkim          #+#    #+#             */
/*   Updated: 2023/06/07 21:18:59 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	_err_(char **ptr, int err_code)
{
	if (ptr)
		free_ptr(ptr);
	if (!err_code)
		write(2, "error: invalid map file\n", 24);
	else
		perror("error");
	exit(EXIT_FAILURE);
}

void	get_coordinate(t_map *map, char **lines)
{
	size_t	i;
	size_t	j;
	char	**split;

	i = 0;
	while (i < map->y_size)
	{
		if (get_split_size(lines[i], ' ') != map->x_size)
			_err_(lines, 0);
		split = ft_split(lines[i], ' ', map->x_size);
		if (!split)
			_err_(lines, 1);
		j = 0;
		while (j < map->x_size)
		{
			init_pos(map, j, i, split[j]);
			j++;
		}
		free_ptr(split);
		i++;
	}
}

void	get_map_info(char *file, t_map *map)
{
	int		fd;
	char	*line;
	char	**lines;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("fail to open file");
		exit(EXIT_FAILURE);
	}
	line = map_to_line(fd);
	map->y_size = get_split_size(line, '\n');
	lines = ft_split(line, '\n', map->y_size);
	free(line);
	if (!lines)
		_err_(NULL, 1);
	map->x_size = get_split_size(lines[0], ' ');
	map->pos = malloc(sizeof(t_pos) * map->x_size * map->y_size);
	if (!map->pos)
		_err_(lines, 1);
	get_coordinate(map, lines);
	free_ptr(lines);
}
