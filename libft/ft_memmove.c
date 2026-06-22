/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 13:11:21 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 17:09:35 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!src && !dst)
		return (dst);
	d = dst;
	s = src;
	if (d > s)
		while (len--)
			*(d + len) = *(s + len);
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
