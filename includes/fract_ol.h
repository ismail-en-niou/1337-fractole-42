#ifndef FRACT_OL
#define FRACT_OL
#include "ft_printf.h"
#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#define ESC 53
#define LEFT 123
#define RIGHT 124
#define TOP 126
#define BOTTOM 127
#define MANDELBROT 0
#define JULIA 1
#define BURNING_SHIP 2
#define PLUS 69
#define MINUS 78

#define WIDTH 550
#define HEIGHT 550


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

int	ft_strncmp(const char *s1, const char *s2, size_t n);
float   ft_atof(const char *str);
int mandel(double c_real , double c_img , int max_iterat);
int get_color(int iter, int max_iter);
void draw_fractal(t_data *data , int max_iter);
int julia(double z_real, double z_imag, double c_real, double c_imag, int max_iter);
int mouse_hook(int button, int x, int y, t_data *vars);
int key_hook_bonnus(int keycode, t_data *vars);

enum {
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
};


#endif