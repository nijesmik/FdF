/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:08:57 by sejinkim          #+#    #+#             */
/*   Updated: 2023/05/29 18:13:06 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
	{
		write(2, "error : input only one argument with map file!\n", 47);
		return (EXIT_FAILURE);
	}
	get_map_info(av[1], &map);
	get_pixel(&map);
	get_mlx(&map);
	free(map.pos);
	return (0);
}

// export DYLD_LIBRARY_PATH=./minilibx