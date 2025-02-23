/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handelers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:10:38 by ien-niou          #+#    #+#             */
/*   Updated: 2025/01/24 10:48:08 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int	mouse_hook(int button, int x, int y, t_data *vars)
{
	(void)x;
	(void)y;
	if (button == 4)
		vars->zoom *= 1.1;
	else if (button == 5)
		vars->zoom *= 0.9;
	draw_fractal(vars, vars->max_iter);
	return (0);
}

int	key_hook_bonnus(int keycode, t_data *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}
