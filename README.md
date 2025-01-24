Here's a structured `README.md` file for your `1337-fractole-42` project, explaining both the mathematical and coding aspects.

---

# 1337-fractole-42

## Project Overview

The **1337-fractole-42** project is a graphical program that displays fractals, focusing on the **Mandelbrot set** and **Julia set** fractals. The program is built using **C** and leverages the **MLX** graphics library for rendering. Users can zoom in, pan, and interact with the fractals through both mouse and keyboard inputs.

### Features:
- Display the Mandelbrot set.
- Display the Julia set.
- Zoom in and out of the fractal images using mouse scroll.
- Pan the fractals using arrow keys.
- Adjust the maximum number of iterations using keyboard shortcuts.
- Exit the program using the ESC key or close the window.

---

## Mathematical Explanation

### Fractals

Fractals are mathematical structures that exhibit self-similarity at different scales. The two primary fractals in this project are:

### 1. **Mandelbrot Set**

The **Mandelbrot set** is defined using the recursive equation:

\[
z_{n+1} = z_n^2 + c
\]

Where:
- \( z_n \) is a complex number at the \(n\)-th iteration.
- \( c \) is a constant complex number representing each point on the complex plane.

The Mandelbrot set consists of all the points \(c\) in the complex plane for which the sequence does not diverge when iterated.

To determine whether a point is part of the Mandelbrot set, we iterate the above equation for a maximum number of iterations. If the magnitude of \( z_n \) exceeds 2 at any point, the sequence is considered to diverge, and the point is not in the set.

### 2. **Julia Set**

The **Julia set** is similar to the Mandelbrot set but instead of iterating over a range of \(c\) values, we fix \(c\) and iterate for different values of \(z\) (initial values in the complex plane).

The equation for the Julia set is:

\[
z_{n+1} = z_n^2 + c
\]

Where:
- \( z_n \) is the complex value that we are iterating.
- \( c \) is a fixed complex parameter, which determines the shape of the Julia set.

The difference between the Mandelbrot and Julia sets is that in the Mandelbrot set, we vary \(c\), and in the Julia set, we vary \(z\).

### Zooming and Panning

- **Zoom**: When zooming, the program maps screen coordinates to complex plane coordinates, adjusting the view of the fractal accordingly.
- **Pan**: Panning allows the user to move the fractal in the complex plane by adjusting the offset values, enabling the user to explore different regions of the fractal.

---

## Code Explanation

### Main Components of the Code

1. **Data Structure**

```c
typedef struct s_data {
    void    *mlx;
    void    *win;
    void    *img;
    double  zoom;
    double  offset_x;
    double  offset_y;
    int     max_iter;
} t_data;
```

- `mlx`: Pointer to the MLX instance.
- `win`: Pointer to the window created by MLX.
- `img`: Pointer to the image that stores the fractal.
- `zoom`: The current zoom level of the fractal.
- `offset_x`, `offset_y`: Offsets for panning the fractal.
- `max_iter`: The maximum number of iterations to compute for each point in the fractal.

2. **Fractal Calculation**

The function `calculate_complex` maps screen coordinates to the complex plane. This is how the zooming and panning are handled:

```c
real = (x - WIDTH / 2.0) / (0.5 * vars->zoom * WIDTH) + vars->offset_x;
imag = (y - HEIGHT / 2.0) / (0.5 * vars->zoom * HEIGHT) + vars->offset_y;
```

- `x`, `y`: The screen coordinates where the mouse is located.
- `vars->zoom`: The current zoom factor.
- `vars->offset_x`, `vars->offset_y`: The panning offsets that move the view of the fractal.

The zoom factor and the offsets allow the user to control the view of the fractal.

3. **Rendering the Fractal**

```c
void draw_fractal(t_data *vars, int max_iter) {
    // Loop through the screen pixels and compute the corresponding fractal values
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Calculate the complex number for each pixel
            complex_number = calculate_complex(x, y, vars);
            // Calculate whether the point is inside the fractal set
            // Update image with color based on iterations
        }
    }
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
```

- This function computes each point on the fractal by iterating over screen coordinates and mapping them to the complex plane.
- The number of iterations is calculated for each point, and based on whether the point diverges, it is colored appropriately.

4. **Zooming and Panning**

```c
void handle_zoom(int x, int y, t_data *vars, double zoom_factor) {
    double real, imag;
    
    real = (x - WIDTH / 2.0) / (0.5 * vars->zoom * WIDTH) + vars->offset_x;
    imag = (y - HEIGHT / 2.0) / (0.5 * vars->zoom * HEIGHT) + vars->offset_y;

    vars->zoom *= zoom_factor;
    vars->offset_x = real - (x - WIDTH / 2.0) / (0.5 * vars->zoom * WIDTH);
    vars->offset_y = imag - (y - HEIGHT / 2.0) / (0.5 * vars->zoom * HEIGHT);
}
```

- This function adjusts the zoom factor and recalculates the offsets to give the user control over zooming and panning.
  
5. **Keyboard and Mouse Interaction**

```c
int mouse_hook(int button, int x, int y, t_data *vars) {
    if (button == 4) // Scroll up (Zoom in)
        handle_zoom(x, y, vars, 1.1);
    else if (button == 5) // Scroll down (Zoom out)
        handle_zoom(x, y, vars, 0.9);
    draw_fractal(vars, vars->max_iter);
    return (0);
}
```

- This allows the user to zoom in and out by scrolling the mouse wheel.
- The panning functionality is handled by key presses such as left, right, up, and down arrows.

---

## How to Build and Run

### Prerequisites:
- **MLX**: The graphics library used for rendering.
- **libft**: The standard C library implementation for string manipulation and I/O functions.
- **printf**: A custom implementation of the printf function.

### Compilation

1. Clone the repository:
```bash
git clone https://github.com/yourusername/1337-fractole-42.git
cd 1337-fractole-42
```

2. Build the project:
```bash
make
```

3. Run the program:
```bash
./fract-ol mandelbrot  # To run Mandelbrot fractal
./fract-ol julia       # To run Julia fractal
```

4. Use the mouse to zoom and pan around the fractals. You can use the keyboard for finer control.

---

## Conclusion

This project demonstrates how fractals can be visualized using C and the MLX library. Through the use of mathematical formulas and efficient code, users can explore the mesmerizing and complex structures of the Mandelbrot and Julia sets.