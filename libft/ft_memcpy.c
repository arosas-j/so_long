/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.comr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:09:13 by arosas-j          #+#    #+#             */
/*   Updated: 2023/05/08 19:57:24 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*x;
	unsigned char	*y;

	if (dst == NULL && src == NULL)
		return (dst);
	i = 0;
	x = (unsigned char *)dst;
	y = (unsigned char *)src;
	while (i < n)
	{
		x[i] = y[i];
		i++;
	}
	return (dst);
}
