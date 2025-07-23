/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:03:39 by arosas-j          #+#    #+#             */
/*   Updated: 2023/09/12 13:26:57 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_mem(long int n)
{
	int	mem;

	mem = 2;
	while (n / 10 >= 1)
	{
		mem++;
		n = n / 10;
	}
	return (mem);
}

static void	put_num(long int n, char *num, int mem)
{
	num[mem - 1] = '\0';
	mem = mem - 2;
	while (mem >= 0)
	{
		num[mem] = (n % 10) + '0';
		n = n / 10;
		mem--;
	}
	return ;
}

char	*ft_uitoa(long int n)
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
