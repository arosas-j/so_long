/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:47:09 by arosas-j          #+#    #+#             */
/*   Updated: 2023/09/12 15:15:41 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char a)
{
	int	printed;

	printed = write(1, &a, 1);
	return (printed);
}

int	ft_putstr(char *str)
{
	int	printed;
	int	i;

	printed = 0;
	i = 0;
	if (!str)
	{
		printed += ft_putstr("(null)");
		return (printed);
	}
	while (str[i])
	{
		printed += ft_putchar(str[i]);
		i++;
	}
	return (printed);
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	else
		return (c);
}
