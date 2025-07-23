/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.comr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:45:09 by arosas-j          #+#    #+#             */
/*   Updated: 2023/05/15 16:45:21 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_start(char const *s1, char const *set)
{
	size_t	start;
	size_t	i;

	i = 0;
	start = 0;
	while (set[i] != '\0')
	{
		if (set[i] == s1[start])
		{
			i = 0;
			start++;
		}
		else
			i++;
	}
	return (start);
}

static size_t	get_end(char const *s1, char const *set)
{
	size_t	end;
	size_t	i;

	i = 0;
	end = ft_strlen(s1) - 1;
	while (set[i] != '\0')
	{
		if (set[i] == s1[end])
		{
			end--;
			i = 0;
		}
		else
			i++;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	end;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL || ft_strlen(s1) == 0)
		return (ft_strdup(s1));
	start = get_start(s1, set);
	end = get_end(s1, set);
	trim = ft_substr(s1, start, end - start + 1);
	return (trim);
}
