/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:23:41 by hel-haia          #+#    #+#             */
/*   Updated: 2023/05/18 22:49:22 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_player(t_data *data, int x, int y)
{
	data->x_player = x;
	data->y_player = y;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player, x * 50, y * 50);
}

static void	put_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, x * 50, y * 50);
}

static void	put_exit(t_data *data, int x, int y)
{
	// if (data->n_collect == 0)
	// {
	// 	mlx_destroy_image(data->con_id, data->exit);
	// 	data->exit = mlx_xpm_file_to_image(data->con_id, DEX, &data->img_width, &data->img_height);
	// }
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit, x * 50, y * 50);
}

int	draw_m(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while(data->lmap[y])
		{
			x = 0;
			while(data->lmap[y][x])
			{
				if (data->lmap[y][x] == '1')
				{
					printf("here\n");
					put_img(data, data->wall, x, y);
				}
				else if (data->lmap[y][x] == '0')
					put_img(data, data->space, x, y);
				else if (data->lmap[y][x] == 'P')
					put_player(data, x, y);
				else if (data->lmap[y][x] == 'C')
					put_img(data, data->collect, x, y);
				else if (data->lmap[y][x] == 'E')
					put_exit(data, x, y);
				x++;
			}
			printf("\n");
			y++;
		}
		
	return (0);
}
