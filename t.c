#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>



// Add max_iter to the t_data struct



// Gradient coloring
int get_color(int iter, int max_iter) {
    double t = (double)iter / max_iter;
    int r = (int)(9 * (1 - t) * t * t * t * 255);
    int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    return (r << 16 | g << 8 | b);
}

// Mandelbrot set calculation
int mandelbrot(double c_real, double c_imag, int max_iter) {
    double z_real = 0, z_imag = 0;
    int iter = 0;
    while (z_real * z_real + z_imag * z_imag <= 4 && iter < max_iter) {
        double temp = z_real * z_real - z_imag * z_imag + c_real;
        z_imag = 2 * z_real * z_imag + c_imag;
        z_real = temp;
        iter++;
    }
    return iter;
}


// Burning Ship calculation
int burning_ship(double c_real, double c_imag, int max_iter) {
    double z_real = 0, z_imag = 0;
    int iter = 0;
    while (z_real * z_real + z_imag * z_imag <= 4 && iter < max_iter) {
        double temp = z_real * z_real - z_imag * z_imag + c_real;
        z_imag = fabs(2 * z_real * z_imag) + c_imag;
        z_real = fabs(temp);
        iter++;
    }
    return iter;
}

// Put a pixel in the image
void put_pixel_to_image(t_data *data, int x, int y, int color) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        char *dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int *)dst = color;
    }
}

// Draw the selected fractal
void draw_fractal(t_data *data, int max_iter) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double real = (x - WIDTH / 2.0) / (0.5 * data->zoom * WIDTH) + data->offset_x;
            double imag = (y - HEIGHT / 2.0) / (0.5 * data->zoom * HEIGHT) + data->offset_y;

            int iter;
            if (data->current_fractal == MANDELBROT)
                iter = mandelbrot(real, imag, max_iter);
            else if (data->current_fractal == JULIA)
                iter = julia(real, imag, data->c_real, data->c_imag, max_iter);
            else
                iter = burning_ship(real, imag, max_iter);

            int color = (iter == max_iter) ? 0x000000 : get_color(iter, max_iter);
            put_pixel_to_image(data, x, y, color);
        }
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}



// Update the handle_keypress function to change max_iter
int handle_keypress(int keycode, t_data *data) {
    if (keycode == 123) data->offset_x -= 0.1 / data->zoom; // Left arrow
    if (keycode == 124) data->offset_x += 0.1 / data->zoom; // Right arrow
    if (keycode == 126) data->offset_y -= 0.1 / data->zoom; // Up arrow
    if (keycode == 125) data->offset_y += 0.1 / data->zoom; // Down arrow
    if (keycode == 24) data->zoom *= 1.1;                  // Plus key
    if (keycode == 27) data->zoom /= 1.1;                  // Minus key
    if (keycode == 18) data->current_fractal = MANDELBROT; // Key 1
    if (keycode == 19) data->current_fractal = JULIA;      // Key 2
    if (keycode == 20) data->current_fractal = BURNING_SHIP; // Key 3
    if (keycode == 53) exit(0);                         // Escape key
    
    // Increase max_iter on '+' key, decrease on '-' key
    if (keycode == 69) data->max_iter += 20;  // Plus key
    if (keycode == 78 && data->max_iter > 20) data->max_iter -= 20; // Minus key

    mlx_clear_window(data->mlx, data->win);
    draw_fractal(data, data->max_iter);  // Use the new max_iter
    return 0;
}

// Handle mouse events for zoom
int handle_mouse(int button, int x, int y, t_data *data) {
    if (button == 4) data->zoom *= 1.1; // Scroll up
    if (button == 5) data->zoom /= 1.1; // Scroll down

    data->offset_x += (x - WIDTH / 2) / (data->zoom * WIDTH);
    data->offset_y += (y - HEIGHT / 2) / (data->zoom * HEIGHT);

    mlx_clear_window(data->mlx, data->win);
    draw_fractal(data, data->max_iter);  // Use the new max_iter
    return 0;
}

// Main function remains the same...


int main(int argc, char **argv) {
    t_data data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fractal Viewer");
    data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
    data.max_iter = 42;  // Set initial iteration count
    if (argc == 3) {
        data.c_real = atof(argv[1]);
        data.c_imag = atof(argv[2]);
        data.current_fractal = JULIA;
    } else {
        data.c_real = -0.7;
        data.c_imag = 0.27015;
    }
    draw_fractal(&data, data.max_iter);  // Use the max_iter for the initial draw
    mlx_key_hook(data.win, handle_keypress, &data);
    mlx_mouse_hook(data.win, handle_mouse, &data);
    mlx_loop(data.mlx);

    return 0;
}
