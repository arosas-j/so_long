/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:16:34 by arosas-j          #+#    #+#             */
/*   Updated: 2023/09/12 13:22:52 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_arg(char format, va_list arg)
{
	int		printed;

	printed = 0;
	if (format == 'c')
		printed += ft_putchar((char)va_arg(arg, int));
	else if (format == 's')
		printed += ft_putstr(va_arg(arg, char *));
	else if (format == 'p')
		printed += ft_format_p(va_arg(arg, unsigned long));
	else if (format == 'd' || format == 'i')
		printed += ft_format_di(va_arg(arg, int));
	else if (format == 'u')
		printed += ft_format_u(va_arg(arg, unsigned int));
	else if (format == 'x')
		printed += ft_format_x(va_arg(arg, unsigned int));
	else if (format == 'X')
		printed += ft_format_upperx(va_arg(arg, unsigned int));
	else if (format == '%')
		printed += ft_putchar('%');
	return (printed);
}
