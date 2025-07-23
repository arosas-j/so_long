/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:54:58 by arosas-j          #+#    #+#             */
/*   Updated: 2024/03/04 15:26:53 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "MLX42/include/MLX42/MLX42.h"

# define TSIZE 32

typedef struct s_textures
{
	mlx_texture_t	*blank;
	mlx_texture_t	*wall;
	mlx_texture_t	*exit;
	mlx_texture_t	*p_left;
	mlx_texture_t	*p_right;
	mlx_texture_t	*collec;
	mlx_texture_t	*enm;
}				t_textures;

typedef struct s_images
{
	mlx_image_t	*blank;
	mlx_image_t	*wall;
	mlx_image_t	*exit;
	mlx_image_t	*p_left;
	mlx_image_t	*p_right;
	mlx_image_t	*coll;
	mlx_image_t	*enm;
}				t_images;

typedef struct s_game
{
	t_images	*img;
	t_textures	*text;
	mlx_t		*mlx;
	char		**map;
	int			height;
	int			width;
	int			collectables;
	int			collected;
	int			moves;
	int			x;
	int			y;
	char		last_move;
}				t_game;

char	**get_map(char *map_file);
int		check_map(char **map, char *map_file);
int		check_rectangle(char **map);
void	free_map(char **map);
int		check_border(char **map);
int		check_char(char **map);
int		check_objects(char **map);
int		check_path(char *map_file);
int		check_flood(char **map);
void	flood_map(int x, int y, char **map);
void	get_start(int *x, int *y, char **map);
int		count_char(char **map, char c);
void	get_map_data(t_game *game);
void	get_textures(t_game *game);
void	get_images(t_game *game);
void	ft_key_hook(mlx_key_data_t keydata, void *param);
void	move_up(t_game *game);
void	move_left(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	update_game(t_game *game);
void	update_collectables(t_game *game);
void	game_to_window(t_game *game);
void	draw_elements(t_game *game);
void	draw_background(t_game *game);
void	draw_player(t_game *game);
int		init_game(t_game *game);

#endif