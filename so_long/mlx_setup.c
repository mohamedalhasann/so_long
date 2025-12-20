/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:01:31 by malhassa          #+#    #+#             */
/*   Updated: 2025/12/20 18:46:25 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_mlx(t_game *game)
{
	
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	return (1);
}
int	create_window(t_game *game)
{
	game->height = ft_2dstrlen(game->map);

	game->width = ft_strlen(game->map[0]) - 1; //  ?
	game->win = mlx_new_window(game->mlx,game->width * TILE_SIZE,game->height * TILE_SIZE,"so_long");
	if (!game->win)
		return (0);
	return (1);
}
int	put_image(t_game *game)
{
	int w;
	int h;
	// why are we using w and h
	game->image.wall = mlx_xpm_file_to_image(game->mlx, "images/wall.xpm", &w, &h);
	game->image.collect = mlx_xpm_file_to_image(game->mlx, "images/collect.xpm", &w, &h);
	game->image.exit = mlx_xpm_file_to_image(game->mlx, "images/exit.xpm", &w, &h);
	game->image.floor = mlx_xpm_file_to_image(game->mlx, "images/floor.xpm", &w, &h);
	game->image.player = mlx_xpm_file_to_image(game->mlx, "images/player.xpm", &w, &h);

	if (!game->image.player || !game->image.wall || !game->image.collect|| !game->image.floor || !game->image.exit)
		return (0);
	return (1);
}
int	render(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while(game->map[i])
	{
		j = 0;
		while(game->map[i][j])
		{
			if(game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx,game->win,game->image.floor, j * TILE_SIZE, i*TILE_SIZE);
			else if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win,game->image.wall, j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,game->image.collect, j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,game->image.exit, j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map[i][j] == 'P')
			{
				game->dimesnsion.x = i;
				game->dimesnsion.y = j;
				mlx_put_image_to_window(game->mlx, game->win,game->image.player, j * TILE_SIZE, i * TILE_SIZE);
			}
			j++;
		}
		i++;
	}
	return (1);
}