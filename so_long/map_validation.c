/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:33:33 by malhassa          #+#    #+#             */
/*   Updated: 2025/12/14 21:25:01 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int	onesonsides(char **map)
{
	int	i;
	int	j;
	int	len;
	
	i = 0;
	while (i < ft_2dstrlen(map))
	{
		len = ft_strlen(map[i]);
		if (len > 0 && map[i][len - 1] == '\n')
			len--;
		if(i == 0 || i == ft_2dstrlen(map) - 1)
		{
			j = 0;
			while (j < len)
			{
				if (map[i][j] != '1')
					return (0);
				j++;
			}
		}
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
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
		while (map[i][j])
		{
			if(map[i][j] == 'P')
				playercounter++;
			else if (map[i][j] == 'C')
				collectcounter++;
			else if (map[i][j] == 'E')
				exitcounter++;
			j++;
		}
		i++;
	}
	return (playercounter == 1 && collectcounter && exitcounter == 1);
}