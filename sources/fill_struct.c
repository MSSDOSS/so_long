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
	int w = 50;
	int h = 50;
	void *f = "ghost_right.xpm";
	printf("nk,jb,bf\n");
	map->player = mlx_xpm_file_to_image(map->mlx_ptr, f, &w, &h); 
	map->wall = mlx_xpm_file_to_image(map->mlx_ptr, f, &w, &h); 
	map->space = mlx_xpm_file_to_image(map->mlx_ptr, f, &w, &h); 
	map->exit = mlx_xpm_file_to_image(map->mlx_ptr, f, &w, &h); 
	map->collect = mlx_xpm_file_to_image(map->mlx_ptr, f, &w, &h);
	ft_check_permissions(map);

}
