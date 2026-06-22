/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatalla <omatalla@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 12:11:36 by omatalla          #+#    #+#             */
/*   Updated: 2026/06/22 17:03:09 by omatalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 	DESCRIPTION
**     The printf() family of functions produces output
**     according to a format.
**
**
**	RETURN VALUE
**		Returns the number of characters printed (excluding the null terminator)
**
**	VARIADIC FUNCTION
**		printf is a variadic function,
			this means it can take a variable number of arguments
**		(including zero arguments) of different types.
**
**
**
*/

#include "ft_printf_bonus.h"

static t_format	init_flags(void)
{
	t_format	fmt;

	ft_bzero(&fmt, sizeof(t_format));
	return (fmt);
}

static const char	*set_flags(t_format *fmt, const char *format)
{
	while (ft_strchr(FLAGS, *format))
	{
		if (*format == '#')
			fmt->flag_hash = 1;
		if (*format == ' ')
			fmt->flag_space = 1;
		if (*format == '+')
			fmt->flag_plus = 1;
		format++;
	}
	return (format);
}

static int	handle_specifier(const char **format, va_list *args)
{
	t_format	fmt;
	int			count;

	(*format)++;
	fmt = init_flags();
	*format = set_flags(&fmt, *format);
	if (!**format)
		return (-1);
	fmt.specifier = **format;
	(*format)++;
	count = ft_printf_format(&fmt, args);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		temp;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			temp = handle_specifier(&format, &args);
			if (temp == -1)
				break ;
			count += temp;
		}
		else
		{
			count += write(1, format, 1);
			format++;
		}
	}
	va_end(args);
	return (count);
}
