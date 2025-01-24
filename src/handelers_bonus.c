/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handelers_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:10:38 by ien-niou          #+#    #+#             */
/*   Updated: 2025/01/24 10:39:07 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	handle_zoom(int x, int y, t_data **vars, double zoom_factor)
{
	double	real;
	double	imag;

	real = (x - WIDTH / 2.0) / (0.5 * (*vars)->zoom * WIDTH)
		+ (*vars)->offset_x;
	imag = (y - HEIGHT / 2.0) / (0.5 * (*vars)->zoom * HEIGHT)
		+ (*vars)->offset_y;
	(*vars)->zoom *= zoom_factor;
	(*vars)->offset_x = real - (x - WIDTH / 2.0) / (0.5 * (*vars)->zoom
			* WIDTH);
	(*vars)->offset_y = imag - (y - HEIGHT / 2.0) / (0.5 * (*vars)->zoom
			* HEIGHT);
}

int	mouse_hook(int button, int x, int y, t_data *vars)
{
	if (button == 4)
		handle_zoom(x, y, &vars, 1.1);
	else if (button == 5)
		handle_zoom(x, y, &vars, 0.9);
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
	else if (keycode == LEFT)
		vars->offset_x -= (0.1 / vars->zoom);
	else if (keycode == RIGHT)
		vars->offset_x += (0.1 / vars->zoom);
	else if (keycode == TOP)
		vars->offset_y -= (0.1 / vars->zoom);
	else if (keycode == BOTTOM)
		vars->offset_y += (0.1 / vars->zoom);
	else if (keycode == PLUS)
		vars->max_iter += 5;
	else if (keycode == MINUS)
		vars->max_iter -= 5;
	draw_fractal(vars, vars->max_iter);
	return (0);
}
