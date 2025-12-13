/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:33:33 by malhassa          #+#    #+#             */
/*   Updated: 2025/12/13 17:01:44 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}
int shape_validation(char   **map)
{
    int i;

	i = 0;
    while(map[i])
    {
	if(map[i+1])
	{
   		if (ft_strlen(map[i] != ft_strlen(map[i+1])))
			return (0);
	}
	i++;
    }
	return (1);
}
int ft_2dstrlen(char **map)
{
	int	i;

	i = 0;
	while(map[i])
		i++;
	return (i);
}
int	onesonsides(char **map)
{
	int	i;
	int	j;
	
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '0')
			return (0);
		j = 1;
		if (i == 0 || i == ft_2dstrlen(map))
		{
			while (map[i][j])
			{
				if (map[i][j] != '1')
					return (0);
				j++;
			}
		}
		else
		{
			while(map[i][j] && map[i][j+1])
				j++;
			if(map[i][j] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}

int	validexit(char **map)
{
	
}

int	validmap(char **map) // 1's on sides , 1 player , 1 collecitble at least
{
	int	i;
	int	j;
	int	playercounter;
	int	collectcounter;
	int	exitcounter;
	
	exitcounter = 0;
	playercounter = 0;
	collectcounter = 0;
	i = 0;
	while(map[i])
	{
		j = 0;
		if(map[i][j] == 'P')
			playercounter++;
		else if (map[i][j] == 'C')
			collectcounter++;
		else if (map[i][j] == 'E')
			exitcounter++;
		i++;
	}
	return (playercounter == 1 && collectcounter && exitcounter == 1);
}