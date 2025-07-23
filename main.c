/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:04:21 by arosas-j          #+#    #+#             */
/*   Updated: 2024/03/08 15:25:32 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_extension(char *map_file)
{
	int	i;

	i = ft_strlen(map_file);
	if (i < 4)
		return (0);
	if (map_file[i - 4] != '.')
		return (0);
	if (map_file[i - 3] != 'b')
		return (0);
	if (map_file[i - 2] != 'e')
		return (0);
	if (map_file[i - 1] != 'r')
		return (0);
	return (1);
}

static void	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "Error\n./so_long map.ber\n", 25);
		exit(1);
	}
	if (!check_extension(argv[1]))
	{
		write(2, "Error\nInvalid extension\n", 25);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_args(argc, argv);
	game.map = get_map(argv[1]);
	if (!game.map)
	{
		ft_printf("Error\nCheck map file\n");
		return (1);
	}
	if (!check_map(game.map, argv[1]))
	{
		ft_printf("Error\nInvalid map layout\n");
		free(game.map);
		return (1);
	}
	get_map_data(&game);
	if (!init_game(&game))
		return (1);
	return (0);
}
