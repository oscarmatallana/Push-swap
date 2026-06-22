/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 12:11:42 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 17:03:42 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "../libft.h"
# include <stdarg.h>
# include <unistd.h>

# define BASE10 "0123456789"
# define BASE16_LOWER "0123456789abcdef"
# define BASE16_UPPER "0123456789ABCDEF"
# define SPECIFIER "cspdiuxX%"
# define FLAGS "# +"

/* ---------------	OS HANDLE	--------------- */
# if defined(__linux__)
#  define PTR_NULL "(nil)"
# elif defined(__APPLE__)
#  define PTR_NULL "0x0"
# endif

typedef struct s_format
{
	int		flag_hash;
	int		flag_space;
	int		flag_plus;
	char	specifier;
}			t_format;

int			ft_printf(const char *format, ...);

/* ---------------	FORMAT DISPATCH	--------------- */
int			ft_printf_format(t_format *fmt, va_list *args);

/* ---------------	PRINT FUNCTION	--------------- */
int			print_c(int c);
int			print_s(char *str);
int			print_di(t_format *fmt, int n);
int			print_p(void *p);
int			print_hexa(t_format *fmt, unsigned int u);

/* ---------------	UTIL	--------------- */
int			ft_putnbr_base(long n, char *base);
int			ft_putnbr_ubase(unsigned long n, char *base);

#endif