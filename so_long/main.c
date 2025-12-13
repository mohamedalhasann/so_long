/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:19:55 by malhassa          #+#    #+#             */
/*   Updated: 2025/12/13 18:21:45 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
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
int ispathvalid(char *input)
{
	int	i;
	
	i = ft_strlen(input);
	if (ft_strncmp(&input[ft_strlen(input) - 4],".ber",4))
		return (0);
	return (1);
}

int main(int argc , char **argv)
{
	int	fd;
	char *line;
	
    if(argc != 2)
	{
		printf("Meow");
        return (0);
	}
	if (!ispathvalid(argv[1]))
	{
		printf("error");
		return (0);
	}	
	fd = open("map.ber", O_RDONLY);
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
	close(fd);
}