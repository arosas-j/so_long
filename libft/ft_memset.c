/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.comr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:37:14 by arosas-j          #+#    #+#             */
/*   Updated: 2023/05/08 15:26:05 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			n;
	unsigned char	*ptr;

	n = 0;
	ptr = (unsigned char *)b;
	while (n < len)
	{
		ptr[n] = (unsigned char)c;
		n++;
	}
	return (b);
}
