/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handelers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:10:38 by ien-niou          #+#    #+#             */
/*   Updated: 2025/01/16 14:00:18 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int mouse_hook(int button, int x, int y, t_data *vars)
{
    (void)x;
    (void)y;
    if (button == 4)
        vars->zoom += 0.1;
    else if (button == 5)
        vars->zoom -= 0.1;
    draw_fractal(vars, vars->max_iter);
    return (0);
}

int key_hook_bonnus(int keycode, t_data *vars)
{
    if (keycode == ESC)
    {
        mlx_destroy_image(vars->mlx, vars->img);
        mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
    }
    else if (keycode == LEFT)
    {
        printf("Move Left: %f\n", vars->offset_x);
        vars->offset_x -= (0.5 / vars->zoom);  // Divide by zoom to adjust movement
    }
    else if (keycode == RIGHT)
    {
        printf("Move Right: %f\n", vars->offset_x);
        vars->offset_x += (0.5 / vars->zoom);  // Divide by zoom to adjust movement
    }
    else if (keycode == TOP)
    {
        printf("Move Up: %f\n", vars->offset_y);
        vars->offset_y -= (0.5 / vars->zoom);  // Divide by zoom to adjust movement
    }
    else if (keycode == BOTTOM)
    {
        printf("Move Down: %f\n", vars->offset_y);
        vars->offset_y += (0.5 / vars->zoom);  // Divide by zoom to adjust movement
    }
    else if (keycode == PLUS)
    {
        vars->max_iter += 10;
    }
    else if (keycode == MINUS)
    {
        vars->max_iter -= 10;
    }

    draw_fractal(vars, vars->max_iter);
    return (0);
}
