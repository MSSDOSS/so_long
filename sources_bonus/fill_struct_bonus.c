/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 01:25:12 by hel-haia          #+#    #+#             */
/*   Updated: 2023/05/30 04:58:47 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_permissions(t_data *data)
{
	if (data->player == NULL || data->space == NULL
		|| data->wall == NULL || data->collect == NULL || data->exit == NULL)
	{
		ft_putstr("Error:\nCheck your assets permissions.");
		exit(1);
	}
}

void	initialize_the_struct(t_data *data)
{
	int	i;

	i = 0;
	data->mlx_ptr = mlx_init();
	data->map_w = ft_strlen(data->map[0]) * 50;
	i = 0;
	while (data->map[i] != (void *)0)
		i++;
	data->map_h = i * 50;
	data->win = mlx_new_window(data->mlx_ptr, data->map_w, data->map_h, "so_long");
	data->space = mlx_xpm_file_to_image(data->mlx_ptr, DF, &data->img_w, &data->img_h);
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, DHW, &data->img_w, &data->img_h);
	data->player = mlx_xpm_file_to_image(data->mlx_ptr, D2R, &data->img_w, &data->img_h);
	data->collect = mlx_xpm_file_to_image(data->mlx_ptr, DFR, &data->img_w, &data->img_h);
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr, DEX, &data->img_w, &data->img_h);
	data->enemy = mlx_xpm_file_to_image(data->mlx_ptr, EN, &data->img_w, &data->img_h);
	data->moves = 0;
	ft_check_permissions(data);
	controller(data);
}
