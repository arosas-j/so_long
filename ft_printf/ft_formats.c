/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:49:15 by arosas-j          #+#    #+#             */
/*   Updated: 2023/09/12 15:05:49 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_p(unsigned long n)
{
	char	*str;
	int		printed;

	printed = 0;
	str = ft_hexadecimal(n);
	if (!str)
		return (0);
	printed += ft_putstr("0x");
	printed += ft_putstr(str);
	free (str);
	return (printed);
}

int	ft_format_di(int n)
{
	char	*str;
	int		printed;

	printed = 0;
	str = ft_itoa(n);
	if (!str)
		return (0);
	printed += ft_putstr(str);
	free(str);
	return (printed);
}

int	ft_format_u(unsigned int n)
{
	char	*str;
	int		printed;

	printed = 0;
	str = ft_uitoa(n);
	if (!str)
		return (0);
	printed += ft_putstr(str);
	free(str);
	return (printed);
}

int	ft_format_x(unsigned int n)
{
	char	*str;
	int		printed;

	printed = 0;
	str = ft_hexadecimal(n);
	if (!str)
		return (0);
	printed += ft_putstr(str);
	free(str);
	return (printed);
}

int	ft_format_upperx(unsigned int n)
{
	char	*str;
	int		printed;
	int		i;

	printed = 0;
	i = 0;
	str = ft_hexadecimal(n);
	if (!str)
		return (0);
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	printed += ft_putstr(str);
	free(str);
	return (printed);
}
