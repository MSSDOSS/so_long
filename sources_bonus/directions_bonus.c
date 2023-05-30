/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 06:50:27 by hel-haia          #+#    #+#             */
/*   Updated: 2023/05/30 20:47:27 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_lexite(char **fmap)
{
	int	i;
	int	j;

	i = 0;
	while (fmap[i] != (void *)0)
	{
		j = 0;
		while (fmap[i][j] != '\0')
		{
			if (fmap[i][j] == 'E' && (fmap[i][j -1] == 'P'
						|| fmap[i][j +1] == 'P' || fmap[i -1][j] == 'P'
						|| fmap[i +1][j] == 'P'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	flood_fill(char **fmap, int i, int j, char cp)
{
	while (fmap[i] != (void *)0)
	{
		j = 0;
		while (fmap[i][j] != '\0')
		{
			if (fmap[i][j] == cp && (fmap[i][j -1] == 'P'
						|| fmap[i][j +1] == 'P' || fmap[i -1][j] == 'P'
						|| fmap[i +1][j] == 'P'))
				fmap[i][j] = 'P';
			j++;
		}
		i++;
	}
}

int	check_player_path(char **fmap, int i, int j, char cp)
{
	while (fmap[i] != (void *)0)
	{
		j = 0;
		while (fmap[i][j] != '\0')
		{
			if (fmap[i][j] == cp && (fmap[i][j -1] == 'P'
						|| fmap[i][j +1] == 'P' || fmap[i -1][j] == 'P'
						|| fmap[i +1][j] == 'P'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_all_collects(char **fmap)
{
	int	i;
	int	j;

	i = 0;
	while (fmap[i] != (void *)0)
	{
		j = 0;
		while (fmap[i][j] != '\0')
		{
			if (fmap[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_path(char **v_path)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (check_player_path(v_path, i, j, '0')
		|| check_player_path(v_path, i, j, 'C'))
	{
		flood_fill(v_path, i, j, '0');
		flood_fill(v_path, i, j, 'C');
		flood_fill(v_path, i, j, 'N');
	}
	if (check_lexite(v_path) && check_all_collects(v_path))
	{
		return (1);
	}
	return (0);
}
