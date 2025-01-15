#include "./includes/fract_ol.h"

int main(int ac, char *av[]) {
    t_data data;

    if (ac < 2) {
        ft_printf("Usage:\nmandelbrot ==> mandelbrot\njulia ==> julia [c_real] [c_imag]\n");
        return 0;
    }

    if (strncmp(av[1], "mandelbrot", 11) == 0) {
        data.current_fractal = MANDELBROT;
    } else if (strncmp(av[1], "julia", 6) == 0) {
        data.current_fractal = JULIA;
        if (ac == 4) {
            data.c_real = ft_atof(av[2]);
            data.c_imag = ft_atof(av[3]);
        } else {
            data.c_real = -0.7;
            data.c_imag = 0.27015;
        }
    } else {
        printf("Unknown fractal type: %s\n", av[1]);
        return 1;
    }
    return 0;
}
