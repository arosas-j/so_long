/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:06:47 by arosas-j          #+#    #+#             */
/*   Updated: 2024/03/04 15:34:36 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player(t_game *game)
{
	int	x;
	int	y;

	x = game->x * 32;
	y = game->y * 32;
	mlx_image_to_window(game->mlx, game->img->p_right, x, y);
	mlx_image_to_window(game->mlx, game->img->p_left, x, y);
	game->img->p_left->enabled = false;
}

void	draw_background(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			mlx_image_to_window(game->mlx, game->img->blank, j * 32, i * 32);
			if (game->map[i][j] == '1')
				mlx_image_to_window(game->mlx, game->img->wall, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	draw_elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				mlx_image_to_window(game->mlx, game->img->coll, j * 32, i * 32);
			if (game->map[i][j] == 'E')
				mlx_image_to_window(game->mlx, game->img->exit, j * 32, i * 32);
			if (game->map[i][j] == 'N')
				mlx_image_to_window(game->mlx, game->img->enm, j * 32, i * 32);
			j++;
		}
		i++;
	}
}
