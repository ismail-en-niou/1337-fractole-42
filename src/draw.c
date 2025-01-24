/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:11:35 by ien-niou          #+#    #+#             */
/*   Updated: 2025/01/24 10:09:21 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

static void	put_pixel_to_image(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel
					/ 8));
		*(unsigned int *)dst = color;
	}
}

void	set_pixel(t_data *data, t_draw *dr, int max_iter, t_Complex z)
{
	int	iter;

	if (data->current_fractal == MANDELBROT)
		iter = mandel(z.real, z.imag, max_iter);
	else if (data->current_fractal == JULIA)
		iter = julia(z, (t_Complex){data->c_real, data->c_imag}, max_iter);
	else if (data->current_fractal == BURN)
		iter = burning_ship(z.real, z.imag, max_iter);
	else
		iter = 0;
	if (iter == max_iter)
		dr->color = 0x000000;
	else
		dr->color = get_color(iter, max_iter);
	put_pixel_to_image(data, dr->x, dr->y, dr->color);
}

t_Complex	calculate_complex(t_draw *dr, t_data *data)
{
	t_Complex	z;

	z.real = (dr->x - WIDTH / 2.0) / (0.5 * data->zoom * WIDTH)
		+ data->offset_x;
	z.imag = (dr->y - HEIGHT / 2.0) / (0.5 * data->zoom * HEIGHT)
		+ data->offset_y;
	return (z);
}

void	draw_fractal(t_data *data, int max_iter)
{
	t_draw		dr;
	t_Complex	z;

	dr.y = 0;
	while (dr.y < HEIGHT)
	{
		dr.x = 0;
		while (dr.x < WIDTH)
		{
			z = calculate_complex(&dr, data);
			set_pixel(data, &dr, max_iter, z);
			dr.x++;
		}
		dr.y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
