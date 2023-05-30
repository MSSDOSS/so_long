/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:23:41 by hel-haia          #+#    #+#             */
/*   Updated: 2023/05/31 00:02:46 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player(t_info *info, int x, int y)
{
	info->x_player = x;
	info->y_player = y;
	mlx_put_image_to_window(info->mlx_ptr, info->mlx_win,
		info->player, x * 50, y * 50);
}

void	put_img(t_info *info, void *img, int x, int y)
{
	mlx_put_image_to_window(info->mlx_ptr,
		info->mlx_win, img, x * 50, y * 50);
}

void	put_exit(t_info *info, int x, int y)
{
	if (info->n_collect == 0)
	{
		mlx_destroy_image(info->mlx_ptr, info->exit);
		info->exit = mlx_xpm_file_to_image(info->mlx_ptr, DEX,
				&info->img_w, &info->img_h);
	}
	mlx_put_image_to_window(info->mlx_ptr, info->mlx_win,
		info->exit, x * 50, y * 50);
}

int	map_drawin(t_info *info)
{
	int	y;
	int	x;

	y = 0;
	while (info->map[y])
	{
		x = 0;
		while (info->map[y][x])
		{
			if (info->map[y][x] == '1')
				put_img(info, info->wall, x, y);
			else if (info->map[y][x] == '0')
				put_img(info, info->space, x, y);
			else if (info->map[y][x] == 'P')
				put_player(info, x, y);
			else if (info->map[y][x] == 'C')
				put_img(info, info->collect, x, y);
			else if (info->map[y][x] == 'E')
				put_exit(info, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
