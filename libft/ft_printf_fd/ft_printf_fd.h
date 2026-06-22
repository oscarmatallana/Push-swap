/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 12:11:42 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 17:05:26 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FD_H
# define FT_PRINTF_FD_H

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

int			ft_printf_fd(int fd, const char *format, ...);

/* ---------------	FORMAT DISPATCH	--------------- */
int			ft_printf_format_fd(int fd, t_format *fmt, va_list *args);

/* ---------------	PRINT FUNCTION	--------------- */
int			print_c_fd(int fd, int c);
int			print_s_fd(int fd, char *str);
int			print_di_fd(int fd, t_format *fmt, int n);
int			print_p_fd(int fd, void *p);
int			print_hexa_fd(int fd, t_format *fmt, unsigned int u);

/* ---------------	UTIL	--------------- */
int			ft_putnbr_base_fd(int fd, long n, char *base);
int			ft_putnbr_ubase_fd(int fd, unsigned long n, char *base);

#endif