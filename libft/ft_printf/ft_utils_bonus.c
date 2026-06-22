/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:14:02 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 17:04:55 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putnbr_base(long n, char *base)
{
	long	base_len;
	int		count;

	base_len = ft_strlen(base);
	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}
	if (n >= base_len)
		count += ft_putnbr_base(n / base_len, base);
	count += write(1, &base[n % base_len], 1);
	return (count);
}

int	ft_putnbr_ubase(unsigned long n, char *base)
{
	unsigned long	base_len;
	int				count;

	base_len = ft_strlen(base);
	count = 0;
	if (n >= base_len)
		count += ft_putnbr_ubase(n / base_len, base);
	count += write(1, &base[n % base_len], 1);
	return (count);
}
