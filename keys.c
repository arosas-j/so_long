/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:14:58 by arosas-j          #+#    #+#             */
/*   Updated: 2024/03/06 17:31:11 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->y - 1][game->x] != '1')
	{
		game->y--;
	}
	game->img->p_left->instances->y = game->y * TSIZE;
	game->img->p_right->instances->y = game->y * TSIZE;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
}

void	move_left(t_game *game)
{
	game->img->p_right->enabled = false;
	if (game->map[game->y][game->x - 1] != '1')
	{
		game->x--;
	}
	game->img->p_left->instances->x = game->x * 32;
	game->img->p_right->instances->x = game->x * 32;
	game->img->p_left->enabled = true;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
}

void	move_down(t_game *game)
{
	if (game->map[game->y + 1][game->x] != '1')
	{
		game->y++;
	}
	game->img->p_left->instances->y = game->y * TSIZE;
	game->img->p_right->instances->y = game->y * TSIZE;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
}

void	move_right(t_game *game)
{
	game->img->p_left->enabled = false;
	if (game->map[game->y][game->x + 1] != '1')
	{
		game->x++;
	}
	game->img->p_left->instances->x = game->x * 32;
	game->img->p_right->instances->x = game->x * 32;
	game->img->p_right->enabled = true;
	game->last_move = 'd';
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
}
