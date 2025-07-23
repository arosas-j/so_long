/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:33:54 by arosas-j          #+#    #+#             */
/*   Updated: 2024/01/10 15:36:26 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(char const *s, char c)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			len++;
		i++;
	}
	return (len);
}

static char	*get_str(char const *s, char c, size_t pos)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*str;

	i = 0;
	while (pos > 0)
	{
		while (s[i] == c)
			i++;
		pos--;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	while (s[i] == c)
			i++;
	start = i;
	while (s[i] != c && s[i] != '\0')
		i++;
	end = i;
	str = ft_substr(s, start, end - start);
	return (str);
}

static void	free_split(char **split, size_t i)
{
	while (i-- > 0)
	{
		if (split[i])
			free(split[i]);
	}
	free(split);
	return ;
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	len;

	if (s == NULL)
		return (NULL);
	len = get_len(s, c);
	split = malloc((len + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		split[i] = get_str(s, c, i);
		if (split[i] == NULL)
		{
			free_split(split, i);
			return (NULL);
		}
		i++;
	}
	split[len] = NULL;
	return (split);
}
