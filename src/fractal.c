/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:53:08 by ien-niou          #+#    #+#             */
/*   Updated: 2025/01/16 10:40:44 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int mandel(double c_real, double c_imag, int max_iter) {
    double z_real; 
    double z_imag;
    int iter;

    iter = 0;
    z_imag = 0;
    z_real =0;
    while (z_real * z_real + z_imag * z_imag <= 4 && iter < max_iter) {
        double temp = z_real * z_real - z_imag * z_imag + c_real;
        z_imag = 2 * z_real * z_imag + c_imag;
        z_real = temp;
        iter++;
    }
    return iter;
}

int julia(double z_real, double z_imag, double c_real, double c_imag, int max_iter) {
    int iter;

    iter = 0;
    while (z_real * z_real + z_imag * z_imag <= 4 && iter < max_iter) {
        double temp = z_real * z_real - z_imag * z_imag + c_real;
        z_imag = 2 * z_real * z_imag + c_imag;
        z_real = temp;
        iter++;
    }
    return iter;
}


