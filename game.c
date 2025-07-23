/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:47:55 by arosas-j          #+#    #+#             */
/*   Updated: 2024/03/04 16:12:55 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_game *game)
{
	game->moves = 0;
	game->collected = 0;
	game->last_move = 'd';
	game->mlx = mlx_init(game->width, game->height, "so_long", false);
	if (!game->mlx)
		return (0);
	get_textures(game);
	get_images(game);
	game_to_window(game);
	mlx_key_hook(game->mlx, &ft_key_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free_map(game->map);
	free(game->text);
	free(game->img);
	return (1);
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
	{
		move_up(game);
		update_game(game);
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
	{
		move_left(game);
		update_game(game);
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
	{
		move_down(game);
		update_game(game);
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
	{
		move_right(game);
		update_game(game);
	}
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(game->mlx);
}

void	update_game(t_game *game)
{
	if (game->map[game->y][game->x] == 'C')
	{
		update_collectables(game);
		ft_printf("Bzzzz!\n");
	}
	if (game->map[game->y][game->x] == 'N')
	{
		ft_printf("A wasp! Run away!\n");
		mlx_close_window(game->mlx);
	}
	if (game->map[game->y][game->x] == 'E')
	{
		if (game->collected == game->collectables)
		{
			ft_printf("You got all the flowers! Time to make honey\n");
			mlx_close_window(game->mlx);
		}
	}
}

void	update_collectables(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->collectables)
	{
		if (game->x * 32 == game->img->coll->instances[i].x
			&& game->y * 32 == game->img->coll->instances[i].y)
		{
			game->img->coll->instances[i].enabled = false;
			game->map[game->y][game->x] = '0';
			game->collected++;
			return ;
		}
		i++;
	}
}
