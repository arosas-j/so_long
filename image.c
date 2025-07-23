/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:16:31 by arosas-j          #+#    #+#             */
/*   Updated: 2024/03/04 15:34:49 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_textures(t_textures *textures)
{
	mlx_delete_texture(textures->blank);
	mlx_delete_texture(textures->wall);
	mlx_delete_texture(textures->p_left);
	mlx_delete_texture(textures->collec);
	mlx_delete_texture(textures->p_right);
	mlx_delete_texture(textures->exit);
	mlx_delete_texture(textures->enm);
}

void	get_textures(t_game *game)
{
	game->text = ft_calloc(1, sizeof(t_textures));
	game->text->blank = mlx_load_png("./textures/blank.png");
	game->text->wall = mlx_load_png("./textures/wall.png");
	game->text->exit = mlx_load_png("./textures/exit.png");
	game->text->collec = mlx_load_png("./textures/collectable.png");
	game->text->p_left = mlx_load_png("./textures/p_left.png");
	game->text->p_right = mlx_load_png("./textures/p_right.png");
	game->text->enm = mlx_load_png("./textures/enemy.png");
}

void	get_images(t_game *game)
{
	game->img = ft_calloc(1, sizeof(t_images));
	game->img->blank = mlx_texture_to_image(game->mlx, game->text->blank);
	game->img->wall = mlx_texture_to_image(game->mlx, game->text->wall);
	game->img->exit = mlx_texture_to_image(game->mlx, game->text->exit);
	game->img->coll = mlx_texture_to_image(game->mlx, game->text->collec);
	game->img->p_left = mlx_texture_to_image(game->mlx, game->text->p_left);
	game->img->p_right = mlx_texture_to_image(game->mlx, game->text->p_right);
	game->img->enm = mlx_texture_to_image(game->mlx, game->text->enm);
	free_textures(game->text);
}

void	game_to_window(t_game *game)
{
	draw_background(game);
	draw_elements(game);
	draw_player(game);
}
