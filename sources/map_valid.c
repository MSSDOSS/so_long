/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:46:12 by hel-haia          #+#    #+#             */
/*   Updated: 2023/05/18 02:06:56 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	wall_surround(char **map)
{
	int	i;
	int	j;
	int	tol;

	i = 0;
	j = 0;
	while (map[i])
		i++;
	while (map[0][j] && map[i - 1][j])
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	tol = ft_strlen(map[i]);
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][tol - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	valide(char **map)
{
	int	i;
	int	j;

	if (!map)
		return (0);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'P' && map[i][j] != 'C' && map[i][j] != 'E'
				&& map[i][j] != '0' && map[i][j] != '1')
				return (0);
			j++;
		}
		if (ft_strlen(map[0]) != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}

// static int	fill_pce(t_data *strings)
// {
// 	int	i;
// 	int	j;

// 	strings->n_player = 0;
// 	strings->n_collect = 0;
// 	strings->n_exit = 0;
// 	i = 0;
// 	while (strings->lmap[i])
// 	{
// 		j = 0;
// 		while (strings->lmap[i][j])
// 		{
// 			if (strings->lmap[i][j] == 'P')
// 				strings->n_player++;
// 			else if (strings->lmap[i][j] == 'C')
// 				strings->n_collect++;
// 			else if (strings->lmap[i][j] == 'E')
// 				strings->n_exit++;
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (strings->n_player > 1 || strings->n_collect == 0 || strings->n_exit > 1)
// 		return (0);
// 	return (1);
// }

int	parsing_lmap(t_data *data)
{
	if (wall_surround(data->lmap) && valide(data->lmap)/*&& fill_pce(data->lmap)*/)
		return (1);
	else
		printf("\nmochkil fmap parcing\n");
		printf("\nmochkil fmap parcing\n");
		printf("\nmochkil fmap parcing\n");
	return (0);
}
