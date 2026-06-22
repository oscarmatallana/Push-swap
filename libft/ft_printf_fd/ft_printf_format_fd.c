/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 07:41:42 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 17:05:35 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	ft_printf_format_fd(int fd, t_format *fmt, va_list *args)
{
	int	count;

	count = 0;
	if (fmt->specifier == 'c')
		count += print_c_fd(fd, va_arg(*args, int));
	else if (fmt->specifier == 's')
		count += print_s_fd(fd, va_arg(*args, char *));
	else if (fmt->specifier == 'p')
		count += print_p_fd(fd, va_arg(*args, void *));
	else if (fmt->specifier == 'd' || fmt->specifier == 'i')
		count += print_di_fd(fd, fmt, va_arg(*args, int));
	else if (fmt->specifier == 'u')
		count += ft_putnbr_ubase_fd(fd, va_arg(*args, unsigned int), BASE10);
	else if (fmt->specifier == 'x' || fmt->specifier == 'X')
		count += print_hexa_fd(fd, fmt, va_arg(*args, unsigned int));
	else if (fmt->specifier == '%')
		count += write(fd, "%", 1);
	return (count);
}
