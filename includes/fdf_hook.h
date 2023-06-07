/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejinkim <sejinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:09:28 by sejinkim          #+#    #+#             */
/*   Updated: 2023/06/07 21:55:54 by sejinkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_HOOK_H
# define FDF_HOOK_H

# define KEY_ESC 53

# define BUTTON_RED 17

int	key_hook(int keycode, t_mlx *mlx);
int	button_hook(t_mlx *mlx);

#endif