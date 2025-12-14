/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:34:34 by malhassa          #+#    #+#             */
/*   Updated: 2025/12/14 20:27:30 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int countlines(char *path)
{
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

char    **get_map(char *argv)
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
    {
        free(map);
        return (NULL);
    }
    while (i < lines)
    {
        map[i] = get_next_line(fd);
        if (!map[i])
        {
            // i need to free the map using another function
            close(fd);
            return (NULL);
        }
        i++;
    }
    map[i] = NULL;
    close(fd);
    return (map);
}