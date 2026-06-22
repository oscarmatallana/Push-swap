/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:57:17 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 17:04:06 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_c(int c)
{
	return (write(1, &c, 1));
}

int	print_s(char *str)
{
	int	count;

	if (!str)
		return (write(1, "(null)", 6));
	count = write(1, str, ft_strlen(str));
	return (count);
}

int	print_di(t_format *fmt, int n)
{
	int	count;

	count = 0;
	if (n >= 0 && fmt->flag_plus)
		count += write(1, "+", 1);
	if (n >= 0 && fmt->flag_space && !fmt->flag_plus)
		count += write(1, " ", 1);
	count += ft_putnbr_base(n, BASE10);
	return (count);
}

int	print_p(void *p)
{
	int	count;

	count = 0;
	if (!p)
		return (write(1, PTR_NULL, ft_strlen(PTR_NULL)));
	count += write(1, "0x", 2);
	count += ft_putnbr_ubase((unsigned long)p, BASE16_LOWER);
	return (count);
}

int	print_hexa(t_format *fmt, unsigned int u)
{
	int	count;

	count = 0;
	if (fmt->specifier == 'x')
	{
		if (u > 0 && fmt->flag_hash)
			count += write(1, "0x", 2);
		count += ft_putnbr_ubase(u, BASE16_LOWER);
	}
	else
	{
		if (u > 0 && fmt->flag_hash)
			count += write(1, "0X", 2);
		count += ft_putnbr_ubase(u, BASE16_UPPER);
	}
	return (count);
}
