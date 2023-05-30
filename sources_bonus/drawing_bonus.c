/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:23:41 by hel-haia          #+#    #+#             */
/*   Updated: 2023/05/30 05:00:27 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_player(t_data *data, int x, int y)
{
	data->x_player = x;
	data->y_player = y;
	mlx_put_image_to_window(data->mlx_ptr, data->win,
		data->player, x * 50, y * 50);
}

void	put_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr,
		data->win, img, x * 50, y * 50);
}

void	put_exit(t_data *data, int x, int y)
{
	if (data->n_collect == 0)
	{
		mlx_destroy_image(data->mlx_ptr, data->exit);
		data->exit = mlx_xpm_file_to_image(data->mlx_ptr, DEX,
				&data->img_w, &data->img_h);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win,
		data->exit, x * 50, y * 50);
}

void	put_enemy(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win,
		data->enemy, x * 50, y * 50);
}

int	draw_the_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				put_img(data, data->wall, x, y);
			else if (data->map[y][x] == '0')
				put_img(data, data->space, x, y);
			else if (data->map[y][x] == 'P')
				put_player(data, x, y);
			else if (data->map[y][x] == 'C')
				put_img(data, data->collect, x, y);
			else if (data->map[y][x] == 'E')
				put_exit(data, x, y);
			else if (data->map[y][x] == 'N')
				put_enemy(data, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
