/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:56:21 by ien-niou          #+#    #+#             */
/*   Updated: 2025/01/20 09:55:09 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int	get_color(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)iter / max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	return (r << 16 | g << 8 | b);
}
