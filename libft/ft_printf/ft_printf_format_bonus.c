/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 07:41:42 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 17:03:57 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf_format(t_format *fmt, va_list *args)
{
	int	count;

	count = 0;
	if (fmt->specifier == 'c')
		count += print_c(va_arg(*args, int));
	else if (fmt->specifier == 's')
		count += print_s(va_arg(*args, char *));
	else if (fmt->specifier == 'p')
		count += print_p(va_arg(*args, void *));
	else if (fmt->specifier == 'd' || fmt->specifier == 'i')
		count += print_di(fmt, va_arg(*args, int));
	else if (fmt->specifier == 'u')
		count += ft_putnbr_ubase(va_arg(*args, unsigned int), BASE10);
	else if (fmt->specifier == 'x' || fmt->specifier == 'X')
		count += print_hexa(fmt, va_arg(*args, unsigned int));
	else if (fmt->specifier == '%')
		count += write(1, "%", 1);
	return (count);
}
