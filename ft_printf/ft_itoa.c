/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:03:54 by arosas-j          #+#    #+#             */
/*   Updated: 2023/09/12 13:26:17 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_mem(int n)
{
	int	mem;

	mem = 2;
	if (n == -2147483648)
		return (12);
	if (n < 0)
	{
		mem++;
		n = n * -1;
	}
	while (n / 10 >= 1)
	{
		mem++;
		n = n / 10;
	}
	return (mem);
}

static void	put_num(int n, char *num, int mem)
{
	int	negative;

	num[mem - 1] = '\0';
	mem = mem - 2;
	if (n == -2147483648)
	{
		num[mem] = '8';
		mem--;
		n = -214748364;
	}
	if (n < 0)
	{
		n = n * -1;
		negative = 1;
	}
	while (mem >= 0)
	{
		num[mem] = (n % 10) + '0';
		n = n / 10;
		mem--;
	}
	if (negative == 1)
		num[0] = '-';
	return ;
}

char	*ft_itoa(int n)
{
	char	*num;
	int		mem;

	mem = get_mem(n);
	num = malloc(mem * sizeof(char));
	if (!num)
		return (0);
	put_num(n, num, mem);
	return (num);
}
