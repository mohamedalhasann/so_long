/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:01:31 by malhassa          #+#    #+#             */
/*   Updated: 2025/12/18 13:09:39 by malhassa         ###   ########.fr       */
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
	game->width = ft_strlen(game->map[0] - 1); //?
	game->win = mlx_new_window(game->mlx,14 * TILE_SIZE,6* TILE_SIZE,"so_long");
	if (!game->win)
		return (0);
	return (1);
}

int	put_image(t_game *game)
{
	game->wall.wall = mlx_xpm_file_to_image(&game->mlx,"images/wall.xpm",&game->width,&game->height);
	game->collect.collect = mlx_xpm_file_to_image(&game->mlx,"images/collect.xpm",&game->width,&game->height);
	game->exit.exit = mlx_xpm_file_to_image(&game->mlx,"images/exit.xpm",&game->width,&game->height);
	game->floor.floor = mlx_xpm_file_to_image(&game->mlx,"images/floor.xpm",&game->width,&game->height);
	game->player.player = mlx_xpm_file_to_image(&game->mlx,"images/player.xpm",&game->width,&game->height);
	if (!game->player.player || !game->wall.wall || !game->collect.collect || !game->floor.floor || !game->exit.exit)
		return (0);
	return (1);
}