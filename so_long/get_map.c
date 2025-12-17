/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:34:34 by malhassa          #+#    #+#             */
/*   Updated: 2025/12/16 16:11:18 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int countlines(char *path)
{
    // i guess no leaks here
    int fd;
    char    *buffer;
    int counter;

    fd = open(path,O_RDONLY);
    counter = 0;
    if (fd < 0)
        return (-1);
    while ((buffer = get_next_line(fd)))
    {
        free(buffer);
        counter++;   
    }
    close(fd);
    return (counter);
}
char    **get_map(char *argv) // this function is converting argv[1] to a 2d character array
{
    int i;
    int fd;
    char    **map;
    int lines;

    lines = countlines(argv);
    if (lines <= 0)
        return (NULL);
    map = malloc(sizeof(char *) * (lines + 1));
    if (!map)
        return (NULL);
    i = 0;
    fd = open(argv,O_RDONLY);
    if (fd < 0)
        return (freemap(map));
    while (i < lines)
    {
        map[i] = get_next_line(fd);
        if (!map[i])
            return (freemapwithclosingfd(map,fd));
        i++;
    }
    map[i] = NULL;
    close(fd);
    return (map);
}

void   findplayer(char **map,t_point *p)
{
    int i;
    int j;

    i = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == 'P')
            {
                p->x = i;
                p->y = j;
                return;
            }
            j++;
        }
        i++;
    }
}
void    floodfill(char **map, int x , int y)
{
    if (!map || x < 0 || y < 0|| !map[0])
        return;
    if (map[x][y] == '1' || map[x][y] == 'M')
        return;
    map[x][y] = 'M';
    floodfill(map,x-1,y);
    floodfill(map,x+1,y);
    floodfill(map,x,y+1);
    floodfill(map,x,y-1);
}
