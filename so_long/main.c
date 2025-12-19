/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:19:55 by malhassa          #+#    #+#             */
/*   Updated: 2025/12/19 22:18:20 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc , char **argv)
{
	t_game game;

	if(argc != 2)
		return (argument_error());
	game.map = get_map(argv[1]);
	if(!game.map)
	{
		printf("failed to read map");
		return (0);
	}
	if (!mapvalidation(argv[1],game.map))
		return (0);
	if (!init_mlx(&game))
		return (0);
	if (!create_window(&game))
		return (0);
	if (!put_image(&game))
		return (0);
	render(&game);
	set_hooks(&game);
	mlx_loop(game.mlx);
	freemap(game.map);
}