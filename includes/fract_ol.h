#ifndef FRACT_OL
#define FRACT_OL
#include "ft_printf.h"
#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#define MANDELBROT 0
#define JULIA 1
#define BURNING_SHIP 2

#define WIDTH 800
#define HEIGHT 800

int	ft_strncmp(const char *s1, const char *s2, size_t n);

typedef struct s_data {
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
    double zoom;
    double offset_x;
    double offset_y;
    int current_fractal;
    int max_iter;
    double c_real;
    double c_imag;
} t_data;

float   ft_atof(const char *str);


#endif