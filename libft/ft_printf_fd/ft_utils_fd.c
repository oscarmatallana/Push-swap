/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:14:02 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 17:05:52 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	ft_putnbr_base_fd(int fd, long n, char *base)
{
	long	base_len;
	int		count;

	base_len = ft_strlen(base);
	count = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		count++;
	}
	if (n >= base_len)
		count += ft_putnbr_base_fd(fd, n / base_len, base);
	count += write(fd, &base[n % base_len], 1);
	return (count);
}

int	ft_putnbr_ubase_fd(int fd, unsigned long n, char *base)
{
	unsigned long	base_len;
	int				count;

	base_len = ft_strlen(base);
	count = 0;
	if (n >= base_len)
		count += ft_putnbr_ubase_fd(fd, n / base_len, base);
	count += write(fd, &base[n % base_len], 1);
	return (count);
}
