/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:46:12 by hel-haia          #+#    #+#             */
/*   Updated: 2023/05/30 06:11:37 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_retangular(char **map)
{
	int	i;

	i = 1;
	if (!map)
		return (0);
	while (map[i] != (void *)0)
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (0);
		i++;
	}
	return (1);
}

int	is_surrounded_by_wall(char **map)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	i = 0;
	while (map[i] != (void *)0)
		i++;
	while (map[0][j] != '\0' && map[i - 1][j] != '\0')
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	len = ft_strlen(map[i]);
	while (map[i] != (void *)0)
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	plyer_collect_exit(t_data *data)
{
	int	i;
	int	j;
	int	n_enemy;

	data->n_collect = 0;
	data->n_player = 0;
	data->n_exit = 0;
	n_enemy = 0;
	i = 0;
	while (data->map[i] != (void *)0)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'P')
				data->n_player++;
			else if (data->map[i][j] == 'E')
				data->n_exit++;
			else if (data->map[i][j] == 'C')
				data->n_collect++;
			else if (data->map[i][j] == 'N')
				n_enemy++;
			j++;
		}
		i++;
	}
	if (data->n_player != 1 || data->n_exit != 1
		|| data->n_collect == 0 || n_enemy == 0)
		return (0);
	return (1);
}

int	is_validate(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != (void *)0)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C'
				&& map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'N')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	map_check(t_data *data)
{
	if (is_retangular(data->map) && is_surrounded_by_wall(data->map)
		&& plyer_collect_exit(data)
		&& is_validate(data->map))
		return (1);
	return (0);
}
