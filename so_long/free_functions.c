/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:45:11 by malhassa          #+#    #+#             */
/*   Updated: 2025/12/19 22:50:33 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
char    **freemapwithclosingfd(char **map,int fd)
{
    int i;

    i = 0;
    while(map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
    close(fd);
    return (NULL);
}
char **	freemap(char **map)
{
	int i;

    i = 0;
    if(!map)
        return (NULL);
    while(map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
    return (0);
}

char	**closefd(int fd)
{
	close(fd);
	return (NULL);
}