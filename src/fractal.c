/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:53:08 by ien-niou          #+#    #+#             */
/*   Updated: 2025/01/23 13:21:35 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int	mandel(double c_real, double c_imag, int max_iter)
{
	double	z_real;
	double	z_imag;
	int		iter;
	double	temp;

	iter = 0;
	z_imag = 0;
	z_real = 0;
	while (z_real * z_real + z_imag * z_imag <= 4 && iter < max_iter)
	{
		temp = z_real * z_real - z_imag * z_imag + c_real;
		z_imag = 2 * z_real * z_imag + c_imag;
		z_real = temp;
		iter++;
	}
	return (iter);
}

int	julia(t_Complex z, t_Complex c, int max_iter)
{
	int		iter;
	double	temp;

	iter = 0;
	while (z.real * z.real + z.imag * z.imag <= 4 && iter < max_iter)
	{
		temp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = temp;
		iter++;
	}
	return (iter);
}

int	burning_ship(double c_real, double c_imag, int max_iter)
{
	t_burn	bu;

	bu.z_real = 0;
	bu.z_imag = 0;
	bu.iter = 0;
	bu.temp_real = 0;
	bu.z_imag_sq = 0;
	bu.z_real_sq = 0;
	while (bu.z_real_sq + bu.z_imag_sq <= 4.0 && bu.iter < max_iter)
	{
		bu.z_real = fabs(bu.z_real);
		bu.z_imag = fabs(bu.z_imag);
		bu.z_real_sq = bu.z_real * bu.z_real;
		bu.z_imag_sq = bu.z_imag * bu.z_imag;
		bu.temp_real = bu.z_real_sq - bu.z_imag_sq + c_real;
		bu.z_imag = 2.0 * bu.z_real * bu.z_imag + c_imag;
		bu.z_real = bu.temp_real;
		bu.iter++;
	}
	return (bu.iter);
}
