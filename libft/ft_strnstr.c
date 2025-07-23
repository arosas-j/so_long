/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.comr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 20:21:18 by arosas-j          #+#    #+#             */
/*   Updated: 2023/05/08 19:00:55 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str;
	size_t	x;
	size_t	y;
	size_t	z;

	x = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[x] != '\0' && x <= len)
	{
		y = x;
		z = 0;
		while (haystack[y] == needle[z] && y < len)
		{
			str = (char *)&haystack[x];
			y++;
			z++;
			if (needle[z] == '\0')
				return (str);
		}
	x++;
	}
	return (NULL);
}
