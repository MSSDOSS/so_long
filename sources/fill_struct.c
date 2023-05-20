/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 01:25:12 by hel-haia          #+#    #+#             */
/*   Updated: 2023/05/18 02:39:07 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_permissions(t_data *data)
{
	if (data->player == NULL || data->space == NULL
		|| data->wall == NULL || data->collect == NULL || data->exit == NULL)
	{
		ft_putstr("Error:\nplease, check the xpm's files permissions");
		exit(1);
	}
}

void	initialize_the_struct(t_data *map)
{
	int	i;
	int	a;
	int	b;

	map->con_id = mlx_init();
	map->m_width = ft_strlen(map->lmap[0]) * 50;
	i = 0;
	while (map->lmap[i] != 0)
		i++;
	printf("\n||%d||\n", i);
	map->m_height = i * 50;
	map->window = mlx_new_window
		(map->con_id, map->m_width, map->m_height, "so_long");
	printf("\n||%d||\n", 2);
	map->space = mlx_xpm_file_to_image
		(map->con_id, DF, &map->img_width, &map->img_height);
	printf("\n||%d||\n", 3);
	map->wall = mlx_xpm_file_to_image
		(map->con_id, DHW, &map->img_width, &map->img_height);
	printf("\n||%d||\n", 4);
	map->player = mlx_xpm_file_to_image
		(map->con_id, D2R, &map->img_width, &map->img_height);
	printf("\n||%d||\n", 5);
	map->collect = mlx_xpm_file_to_image
		(map->con_id, DFR, &map->img_width, &map->img_height);
	printf("\n||%d||\n", 6);
	map->exit = mlx_xpm_file_to_image
		(map->con_id, DEX, &a, &b);
	printf("\n||%d||\n", 7);
	map->moves = 0;
	// ft_check_permissions(map);
	lhook(map);
}
