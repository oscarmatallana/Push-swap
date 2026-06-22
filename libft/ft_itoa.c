/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:25:14 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 17:08:04 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	long	nb;
	int		len;

	nb = n;
	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static void	fill_digits(char *ascii, long nb, int len, int symbol)
{
	int	i;

	i = len - 1;
	while (i >= symbol)
	{
		ascii[i] = '0' + (nb % 10);
		nb /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	size_t	len;
	long	nb;
	int		symbol;
	char	*ascii;

	len = get_len(n);
	nb = n;
	ascii = malloc(len + 1);
	if (!ascii)
		return (NULL);
	ascii[len] = '\0';
	symbol = 0;
	if (nb < 0)
	{
		ascii[0] = '-';
		nb = -nb;
		symbol = 1;
	}
	fill_digits(ascii, nb, len, symbol);
	return (ascii);
}
