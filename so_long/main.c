/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:19:55 by malhassa          #+#    #+#             */
/*   Updated: 2025/12/15 20:26:08 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
static int ispathvalid(char *input)
{
	// not sure 100%%
	if (ft_strncmp(&input[ft_strlen(input) - 4],".ber",4))
		return (0);
	return (1);
}
void	print2d(char **arr)
{
	int	i;

	i = 0;
	while(arr[i])
	{
		printf("%s",arr[i]);
		i++;
	}
}

int main(int argc , char **argv)
{
	char 	**map;
	char	**temp;
	t_point p;

	if(argc != 2)
		return (argument_error());
	if (!ispathvalid(argv[1]))
		return (invalidpath());
	map = get_map(argv[1]);
	if(!map)
	{
		printf("failed to read map");
		return (0);
	}
	if (!onesonsides(map) || !validmap(map))
	{
		freemap(map);
		return (0);
	}
	findplayer(map, &p);
	temp = get_map(argv[1]);
	floodfill(temp,p.x,p.y);
	print2d(temp);
}