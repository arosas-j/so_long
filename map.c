/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:33:03 by arosas-j          #+#    #+#             */
/*   Updated: 2024/03/07 17:43:48 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_str(char *str)
{
	int	i;

	if (str[0] == '\n' || str[ft_strlen(str) - 1] == '\n')
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1])
		{
			if (str[i + 1] == '\n')
				return (0);
		}
		i++;
	}
	return (1);
}

static int	get_collectables(char **map)
{
	int	collectables;
	int	i;
	int	j;

	collectables = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				collectables++;
			j++;
		}
		i++;
	}
	return (collectables);
}

void	get_map_data(t_game *game)
{
	int	height;

	height = 0;
	while (game->map[height])
		height++;
	game->height = height * TSIZE;
	game->width = ft_strlen(game->map[0]) * TSIZE;
	game->collectables = get_collectables(game->map);
	get_start(&game->x, &game->y, game->map);
}

int	check_map(char **map, char *map_file)
{
	if (!check_rectangle(map))
		return (0);
	if (!check_char(map))
		return (0);
	if (!check_border(map))
		return (0);
	if (!check_objects(map))
		return (0);
	if (!check_path(map_file))
		return (0);
	return (1);
}

char	**get_map(char *map_file)
{
	char	**map;
	int		map_fd;
	char	*map_str;
	int		bytes_read;

	map_fd = open(map_file, O_RDONLY);
	if (map_fd < 0)
		return (0);
	map_str = (char *)ft_calloc(10001, sizeof (char));
	if (!map_str)
		return (0);
	bytes_read = read(map_fd, map_str, 10000);
	if (bytes_read == 0 || bytes_read == -1)
	{
		free(map_str);
		return (0);
	}
	close(map_fd);
	if (check_str(map_str))
		map = ft_split(map_str, '\n');
	else
		map = NULL;
	free(map_str);
	return (map);
}
