/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:20:26 by malhassa          #+#    #+#             */
/*   Updated: 2025/12/17 17:00:09 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <mlx.h>
# include "get_next_line/get_next_line.h"

#define TILE_SIZE 52

typedef struct s_point
{
	int x;
	int y;
}				t_point;
typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
}	t_game;
char    **get_map(char *argv);
int countlines(char *path);
int	ft_2dstrlen(char **map);
void   findplayer(char **map, t_point *p);
void    floodfill(char **map, int x , int y);
char    **copy_map(char **map, char *argv);
char    **freemapwithclosingfd(char **map,int fd);
char	**freemap(char **map);
char	**closefd(int fd);
int		argument_error();
int		invalidpath();
int	onesonsides(char **map);
int	validmap(char **map);
int	shapevalidation(char **map);
int	charactersvalidation(char **map);
int	floodfillvalidation(char **map);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	print2d(char **arr);
int ispathvalid(char *input);
int	mapvalidation(char *argv, char **map);
int	init_mlx(t_game *game);
int	create_window(t_game *game);
int	get_map_width(char **map);

