/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:20:26 by malhassa          #+#    #+#             */
/*   Updated: 2025/12/15 20:05:03 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "get_next_line/get_next_line.h"
typedef struct s_point
{
	int x;
	int y;
}				t_point;
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