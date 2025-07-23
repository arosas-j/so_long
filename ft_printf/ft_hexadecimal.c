/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:11:14 by arosas-j          #+#    #+#             */
/*   Updated: 2023/09/12 15:02:12 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_strhex(unsigned long n, char *str, int size)
{
	char	hex[17];

	ft_strlcpy(hex, "0123456789abcdef", 17);
	size--;
	str [size] = '\0';
	size--;
	while (size > 0)
	{
		str[size] = hex[n % 16];
		n = n / 16;
		size--;
	}
	str[size] = hex[n];
}

static int	ft_gethexsize(unsigned long n)
{
	int	size;

	size = 2;
	while (n > 15)
	{
		n = n / 16;
		size++;
	}
	return (size);
}

char	*ft_hexadecimal(unsigned long n)
{
	char	*str;
	int		size;

	size = ft_gethexsize(n);
	str = malloc(size * sizeof(char));
	if (!str)
		return (0);
	ft_strhex(n, str, size);
	return (str);
}
