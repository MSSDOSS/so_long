/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:46:12 by hel-haia          #+#    #+#             */
/*   Updated: 2023/05/31 00:05:43 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	plyer_collect_exit(t_info *info)
{
	int	i;
	int	j;

	info->n_collect = 0;
	info->n_player = 0;
	info->n_exit = 0;
	i = 0;
	while (info->map[i] != (void *)0)
	{
		j = 0;
		while (info->map[i][j] != '\0')
		{
			if (info->map[i][j] == 'P')
				info->n_player++;
			else if (info->map[i][j] == 'E')
				info->n_exit++;
			else if (info->map[i][j] == 'C')
				info->n_collect++;
			j++;
		}
		i++;
	}
	if (info->n_player != 1 || info->n_exit != 1 || info->n_collect == 0)
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
				&& map[i][j] != '0' && map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_the_map(t_info *info)
{
	if (is_retangular(info->map) && is_surrounded_by_wall(info->map)
		&& plyer_collect_exit(info)
		&& is_validate(info->map))
		return (1);
	return (0);
}
