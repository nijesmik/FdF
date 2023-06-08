/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:08:57 by sejinkim          #+#    #+#             */
/*   Updated: 2023/06/09 01:08:32 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac != 2)
	{
		write(2, "error: invalid arguments\n", 25);
		return (EXIT_FAILURE);
	}
	get_map_info(av[1], &vars.map);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fdf");	
	projection(&vars, PI / 4, 0, PI / 4);
	mlx_hooks(&vars);
	mlx_loop(vars.mlx);
	free(vars.map.pos);
	return (0);
}
