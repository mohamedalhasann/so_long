/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:03:15 by mohamed           #+#    #+#             */
/*   Updated: 2025/12/21 20:03:07 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
int	collectiblevalidation(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
void	moveplayer(t_game *game, int x, int y)
{
	if (game->map[game->dimesnsion.x + x][game->dimesnsion.y+y] == '1')
		return;
	else if (game->map[game->dimesnsion.x+x][game->dimesnsion.y+y] == 'E')
	{
	if (collectiblevalidation(game->map))
		x_button(game);
	game->map[game->dimesnsion.x][game->dimesnsion.y] = '0';
	game->dimesnsion.x += x;
	game->dimesnsion.y += y;
	}
	else if (game->map[game->dimesnsion.x+x][game->dimesnsion.y+y] == '0' || game->map[game->dimesnsion.x+x][game->dimesnsion.y+y] == 'C')
	{
		if(!(game->map[game->dimesnsion.x][game->dimesnsion.y] == 'E'))
			game->map[game->dimesnsion.x][game->dimesnsion.y] = '0';
		game->map[game->dimesnsion.x+x][game->dimesnsion.y+y] = 'P';
		game->dimesnsion.x += x;
		game->dimesnsion.y += y;
	}
	mlx_clear_window(game->mlx, game->win);
	render(game);
}
int    x_button(t_game *game)
{
    freemap(game->map);
	mlx_destroy_image(game->mlx,game->image.wall);
	mlx_destroy_image(game->mlx,game->image.floor);
	mlx_destroy_image(game->mlx,game->image.collect);
	mlx_destroy_image(game->mlx,game->image.exit);
	mlx_destroy_image(game->mlx,game->image.player);
	mlx_destroy_window(game->mlx,game->win);
    mlx_destroy_display(game->mlx);
    free(game->mlx);
    exit(0);
    return (0);
}
int    other_keys(int key,t_game *game)
{
    if (key == 65307)
        x_button(game);
    else if (key == 119)
        moveplayer(game,-1,0);
    else if (key == 115)
        moveplayer(game, 1 ,0);
    else if (key == 97)
        moveplayer(game,0,-1);
    else if (key == 100)
        moveplayer(game,0,1);
    return (0);
}
void	set_hooks(t_game *game)
{
	mlx_hook(game->win, 17, 0, x_button, game);
	mlx_hook(game->win, 2, 1L << 0, other_keys, game);
}
