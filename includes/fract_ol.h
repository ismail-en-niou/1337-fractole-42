/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:43:13 by ien-niou          #+#    #+#             */
/*   Updated: 2025/01/24 10:05:17 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# include "../libft/libft.h"
# include "ft_printf.h"
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define TOP 126
# define BOTTOM 125
# define MANDELBROT 0
# define JULIA 1
# define BURN 2
# define BURNING_SHIP 2
# define PLUS 69
# define MINUS 78

# define WIDTH	400
# define HEIGHT 400

typedef struct s_draw
{
	int		x;
	int		y;
	double	real;
	double	imag;
	int		iter;
	int		color;
}			t_draw;

typedef struct s_atof
{
	float	res;
	float	frac;
	int		sign;
	int		i;
	int		div;
}			t_atof;

typedef struct s_burn
{
	double	z_real;
	double	z_imag;
	double	z_real_sq;
	double	z_imag_sq;
	int		iter;
	double	temp_real;
}			t_burn;

typedef struct s_Complex
{
	double	real;
	double	imag;
}			t_Complex;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	zoom;
	double	offset_x;
	double	offset_y;
	int		current_fractal;
	int		max_iter;
	double	c_real;
	double	c_imag;
	int		pow;
}			t_data;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
double		ft_atof(char *s);
int			mandel(double c_real, double c_img, int max_iterat);
int			get_color(int iter, int max_iter);
void		draw_fractal(t_data *data, int max_iter);
int			julia(t_Complex z, t_Complex c, int max_iter);
int			mouse_hook(int button, int x, int y, t_data *vars);
int			key_hook_bonnus(int keycode, t_data *vars);
int			burning_ship(double c_real, double c_imag, int max_iter);

enum
{
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
};

#endif
