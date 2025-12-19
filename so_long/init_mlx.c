/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:01:31 by malhassa          #+#    #+#             */
/*   Updated: 2025/12/19 22:29:04 by mohamed          ###   ########.fr       */
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

	game->width = ft_strlen(game->map[0]) - 1; // make sure 
	game->win = mlx_new_window(game->mlx,game->width * TILE_SIZE,game->height * TILE_SIZE,"so_long");
	if (!game->win)
		return (0);
	return (1);
}
int	put_image(t_game *game)
{
	int w;
	int h;

	game->wall.wall = mlx_xpm_file_to_image(game->mlx, "images/wall.xpm", &w, &h);
	game->collect.collect = mlx_xpm_file_to_image(game->mlx, "images/collect.xpm", &w, &h);
	game->exit.exit = mlx_xpm_file_to_image(game->mlx, "images/exit.xpm", &w, &h);
	game->floor.floor = mlx_xpm_file_to_image(game->mlx, "images/floor.xpm", &w, &h);
	game->player.player = mlx_xpm_file_to_image(game->mlx, "images/player.xpm", &w, &h);

	if (!game->player.player || !game->wall.wall || !game->collect.collect|| !game->floor.floor || !game->exit.exit)
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
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win,game->wall.wall, j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,game->collect.collect, j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,game->exit.exit, j * TILE_SIZE, i * TILE_SIZE);
			else if (game->map[i][j] == 'P')
			{
				game->x.x = i;
				game->y.y = j;
				mlx_put_image_to_window(game->mlx, game->win,game->player.player, j * TILE_SIZE, i * TILE_SIZE);
			}
			j++;
		}
		i++;
	}
	return (1);
}