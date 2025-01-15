/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ien-niou <ien-niou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:48:20 by ien-niou          #+#    #+#             */
/*   Updated: 2025/01/14 11:35:25 by ien-niou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_format(va_list va, char *str, size_t *counter)
{
	if (*str == 'c')
		ft_putchar_pf(va_arg(va, int), counter);
	else if (*str == 's')
		ft_putstr_pf(va_arg(va, char *), counter);
	else if (*str == 'p')
		ft_putptr_pf(va_arg(va, void *), counter);
	else if (*str == 'i' || *str == 'd')
		ft_putnbr_pf(va_arg(va, int), counter);
	else if (*str == 'u')
		ft_putuint(va_arg(va, unsigned int), counter);
	else if (*str == 'x' || *str == 'X')
	{
		if (*str == 'x')
			ft_putnbr_hex_pf(va_arg(va, unsigned int), counter, 1);
		else
			ft_putnbr_hex_pf(va_arg(va, unsigned int), counter, 0);
	}
	else if (*str == '%')
		ft_putchar_pf(*str, counter);
}

int	ft_printf(char const *str, ...)
{
	va_list	va;
	size_t	counter;

	if (!str)
		return (0);
	if (write(1, "", 0) == -1)
		return (-1);
	counter = 0;
	va_start(va, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			ft_format(va, (char *)str, &counter);
		}
		else if ((*str == '%' && *(str + 1) == '%') || *str != '%')
			ft_putchar_pf(*str, &counter);
		str++;
	}
	va_end(va);
	return (counter);
}
