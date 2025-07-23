/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:34:52 by arosas-j          #+#    #+#             */
/*   Updated: 2024/03/04 15:44:09 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_char(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	get_start(int *x, int *y, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*y = i;
				*x = j;
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}

void	flood_map(int x, int y, char **map)
{
	map[x][y] = 'X';
	if (map[x + 1][y] != 'X' && map[x + 1][y] != '1' && map[x + 1][y] != 'N')
		flood_map(x + 1, y, map);
	if (map[x - 1][y] != 'X' && map[x - 1][y] != '1' && map[x - 1][y] != 'N')
		flood_map(x - 1, y, map);
	if (map[x][y + 1] != 'X' && map[x][y + 1] != '1' && map[x][y + 1] != 'N')
		flood_map(x, y + 1, map);
	if (map[x][y - 1] != 'X' && map[x][y - 1] != '1' && map[x][y - 1] != 'N')
		flood_map(x, y - 1, map);
}

int	check_flood(char **map)
{
	int	is_valid;
	int	i;
	int	j;

	is_valid = 1;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'C' || map[i][j] == 'E')
				is_valid = 0;
			j++;
		}
		i++;
	}
	return (is_valid);
}
