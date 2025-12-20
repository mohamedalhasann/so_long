/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:33:33 by malhassa          #+#    #+#             */
/*   Updated: 2025/12/20 15:37:31 by malhassa         ###   ########.fr       */
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


int	validcounters(char **map)
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

int	floodfillvalidation(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
int	shapevalidation(char **map)
{
	int		i;
	size_t	ref;
	size_t	current;

	if (!map || !map[0])
		return (0);

	ref = ft_strlen(map[0]);
	if (ref > 0 && map[0][ref - 1] == '\n')
		ref--;

	i = 0;
	while (map[i])
	{
		current = ft_strlen(map[i]);
		if (current > 0 && map[i][current - 1] == '\n')
			current--;
		if (current != ref)
			return (0);
		i++;
	}
	return (1);
}

int	charactersvalidation(char **map)
{
	int	i;
	int	j;
	char	c;
	if (!map || !map[0])
		return (0);
	i = 0; 
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			c = map[i][j];
			if(c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P' && c != '\n')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	mapvalidation(char *argv, char **map)
{
	char	**temp;
	t_point p;
	
	if (!ispathvalid(argv))
		return (invalidpath());
	if (!onesonsides(map) || !validcounters(map) || !shapevalidation(map) || !charactersvalidation(map))
	{
		printf("error\n"); // hafds
		freemap(map);
		return (0);
	}
	findplayer(map, &p);
	temp = get_map(argv);
	floodfill(temp,p.x,p.y);
	if(!floodfillvalidation(temp))
	{
		freemap(temp);
		freemap(map);
		printf("flood fill error");
		return (0);
	}
	freemap(temp);
	return (1);
}