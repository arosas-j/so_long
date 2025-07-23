/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.comr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:34:57 by arosas-j          #+#    #+#             */
/*   Updated: 2023/05/08 15:48:08 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d;
	size_t	n;
	size_t	aux;

	if (ft_strlen(dst) >= dstsize)
		return (dstsize + ft_strlen(src));
	d = ft_strlen(dst);
	n = 0;
	aux = ft_strlen(dst);
	while (src[n] != '\0' && d < dstsize - 1)
	{
		dst[d] = src[n];
		d++;
		n++;
	}
	dst[d] = '\0';
	return (ft_strlen(src) + aux);
}
