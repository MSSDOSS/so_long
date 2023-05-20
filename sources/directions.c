/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 06:50:27 by hel-haia          #+#    #+#             */
/*   Updated: 2023/05/16 03:04:48 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

func_check()
{
	
}

int	directions(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (func_check())
	{
		i = 0;
		while (map[i])
		{
			j = 0;
			while (map[i][j])
			{
				if (map[i][j] == 'E' && 
					(map[i][j - 1] == 'P' || map[i][j + 1] == 'P'
					|| map[i - 1][j] == 'P' || map[i + 1][j] == 'P'))
				
			}
		}
	}
}