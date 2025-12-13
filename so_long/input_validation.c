/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhassa <malhassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 14:25:36 by malhassa          #+#    #+#             */
/*   Updated: 2025/12/13 14:33:52 by malhassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int ispathvalid(char *input)
{
	int	i;
	
	i = 0;
	while(input[i] != '.' && input[i])
		i++;
	if (strncmp(&input[i],".ber",4))
		return (0);
	return (1);
}