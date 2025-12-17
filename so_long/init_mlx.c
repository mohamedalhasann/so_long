/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:01:31 by malhassa          #+#    #+#             */
/*   Updated: 2025/12/17 16:59:41 by malhassa         ###   ########.fr       */
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
	game->win = mlx_new_window(game->mlx,game->width * TILE_SIZE,game->height * TILE_SIZE,"so_long");
	if (!game->win)
		return (0);
	return (1);
}
