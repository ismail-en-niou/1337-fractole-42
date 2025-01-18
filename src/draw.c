/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:11:35 by ien-niou          #+#    #+#             */
/*   Updated: 2025/01/16 12:47:31 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

static void put_pixel_to_image(t_data *data, int x, int y, int color) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        char *dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int *)dst = color;
    }
}

void draw_fractal(t_data *data, int max_iter) {
    int x;
    int y;
    double real;
    double imag;
    int iter;
    int color;
    
    y = 0;
    while (y < HEIGHT) {
        x = 0;
        while (x < WIDTH) {
            real = (x - WIDTH / 2.0) / (0.5 * data->zoom * WIDTH) + data->offset_x;
            imag = (y - HEIGHT / 2.0) / (0.5 * data->zoom * HEIGHT) + data->offset_y;
            if (data->current_fractal == MANDELBROT) {
                iter = mandel(real, imag, max_iter);
            }else if (data->current_fractal == JULIA) 
            {
                iter = julia(real, imag, data->c_real, data->c_imag, max_iter); 
            }
            else {
                iter = 0;
            }
            if (iter == max_iter)
                color = 0x000000;
            else
                color = get_color(iter, max_iter);
            put_pixel_to_image(data, x, y, color);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
