/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:04:59 by ien-niou          #+#    #+#             */
/*   Updated: 2025/01/14 11:35:53 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putuint(unsigned int num, size_t *counter)
{
	if (num > 9)
		ft_putuint((num / 10), counter);
	ft_putchar_pf(('0' + num % 10), counter);
}
