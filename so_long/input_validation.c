/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamed <mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:25:36 by malhassa          #+#    #+#             */
/*   Updated: 2025/12/14 21:22:19 by mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	ft_2dstrlen(char **map)
{
	int	i;

	i = 0;
	while(map[i])
		i++;
	return (i);
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
