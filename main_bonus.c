/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:11:39 by ien-niou          #+#    #+#             */
/*   Updated: 2025/01/24 10:53:43 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fract_ol.h"

void	handler(t_data *test)
{
	test->mlx = mlx_init();
	test->win = mlx_new_window(test->mlx, WIDTH, HEIGHT, "fractol");
	test->img = mlx_new_image(test->mlx, WIDTH, HEIGHT);
	test->addr = mlx_get_data_addr(test->img, &test->bits_per_pixel,
			&test->line_length, &test->endian);
	test->max_iter = 10;
	mlx_mouse_hook(test->win, mouse_hook, test);
	mlx_key_hook(test->win, key_hook_bonnus, test);
	draw_fractal(test, test->max_iter);
	mlx_put_image_to_window(test->mlx, test->win, test->img, 0, 0);
	mlx_loop(test->mlx);
}

int	main(int ac, char *av[])
{
	t_data	data;

	if (ac < 2)
		return (ft_printf("Usage:\n=>mandelbrot\n=>julia[r][i]\n=>burn"));
	if (ft_strncmp(av[1], "mandelbrot", 11) == 0 && ac == 2)
		data.current_fractal = MANDELBROT;
	else if (ft_strncmp(av[1], "burn", 4) == 0 && ac == 2)
		data.current_fractal = BURN;
	else if (ft_strncmp(av[1], "julia", 6) == 0)
	{
		data.current_fractal = JULIA;
		if (ac == 4)
		{
			data.c_real = ft_atof(av[2]);
			data.c_imag = ft_atof(av[3]);
		}
		else
			return (ft_printf("invalid args: julia [c_real] [c_imag]\n"));
	}
	else
		return (ft_printf("Unknown fractal type: %s\n", av[1]));
	data.zoom = 0.4;
	handler(&data);
	return (0);
}
