/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:48:18 by arosas-j          #+#    #+#             */
/*   Updated: 2024/03/06 17:03:22 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangle(char **map)
{
	int	i;
	int	len;

	i = 0;
	if (!map)
		return (0);
	if (!map[0])
		return (0);
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	check_border(char **map)
{
	size_t	i;
	size_t	j;
	size_t	line;

	line = 0;
	while (map[line])
		line++;
	i = 0;
	while (i < ft_strlen(map[0]))
	{
		if (map[0][i] != '1' || map[line - 1][i] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (j < (line - 1))
	{
		if (map[j][0] != '1' || map[j][ft_strlen(map[0]) - 1] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'N'
			&& map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_objects(char **map)
{
	int	start;
	int	exit;
	int	collectables;

	start = count_char(map, 'P');
	exit = count_char(map, 'E');
	collectables = count_char(map, 'C');
	if (start != 1 || exit != 1 || collectables < 1)
		return (0);
	return (1);
}

int	check_path(char *map_file)
{
	char	**map;
	int		start[2];
	int		path_is_valid;

	map = get_map(map_file);
	get_start(start, start + 1, map);
	flood_map(start[1], start[0], map);
	path_is_valid = check_flood(map);
	free_map(map);
	return (path_is_valid);
}
