/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_keys_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:39:08 by hel-haia          #+#    #+#             */
/*   Updated: 2023/05/31 00:19:29 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_update_image(char key, t_info *info)
{
	mlx_destroy_image(info->mlx_ptr, info->player);
	if (key == 'q')
		info->player = mlx_xpm_file_to_image
			(info->mlx_ptr, ZR, &info->img_w, &info->img_h);
	else if (key == 'z')
		info->player = mlx_xpm_file_to_image
			(info->mlx_ptr, ZL, &info->img_w, &info->img_h);
	else if (key == 'd')
		info->player = mlx_xpm_file_to_image
			(info->mlx_ptr, ZR, &info->img_w, &info->img_h);
	else if (key == 's')
		info->player = mlx_xpm_file_to_image
			(info->mlx_ptr, ZL, &info->img_w, &info->img_h);
}

void	player_q(t_info *info)
{
	player_update_image('q', info);
	if ((info->map[info->y_player][info->x_player] == 'E'
		&& info->n_collect == 0) ||
		(info->map[info->y_player][info->x_player] == 'N'))
	{
		mlx_clear_window(info->mlx_ptr, info->mlx_win);
		info->map[info->y_player + 1][info->x_player] = '0';
		info->moves++;
		exit(0);
	}
	else if (info->map[info->y_player][info->x_player] == '1'
		|| info->map[info->y_player][info->x_player] == 'E')
		info->y_player += 1;
	else
	{
		mlx_clear_window(info->mlx_ptr, info->mlx_win);
		if (info->map[info->y_player][info->x_player] == 'C')
			info->n_collect -= 1;
		info->map[info->y_player][info->x_player] = 'P';
		info->map[info->y_player + 1][info->x_player] = '0';
		info->moves++;
		enemy_anime(info);
		map_drawin(info);
	}
}

void	player_z(t_info *info)
{
	player_update_image('z', info);
	if ((info->map[info->y_player][info->x_player] == 'E'
		&& info->n_collect == 0)
		|| (info->map[info->y_player][info->x_player] == 'N'))
	{
		mlx_clear_window(info->mlx_ptr, info->mlx_win);
		info->map[info->y_player - 1][info->x_player] = '0';
		info->moves++;
		map_drawin(info);
		exit(0);
	}
	else if (info->map[info->y_player][info->x_player] == '1'
		|| info->map[info->y_player][info->x_player] == 'E')
		info->y_player -= 1;
	else
	{
		mlx_clear_window(info->mlx_ptr, info->mlx_win);
		if (info->map[info->y_player][info->x_player] == 'C')
			info->n_collect -= 1;
		info->map[info->y_player][info->x_player] = 'P';
		info->map[info->y_player - 1][info->x_player] = '0';
		info->moves++;
		enemy_anime(info);
		map_drawin(info);
	}
}

void	player_d(t_info *info)
{
	player_update_image('d', info);
	if ((info->map[info->y_player][info->x_player] == 'E'
		&& info->n_collect == 0)
		|| (info->map[info->y_player][info->x_player] == 'N'))
	{
		mlx_clear_window(info->mlx_ptr, info->mlx_win);
		info->map[info->y_player][info->x_player - 1] = '0';
		info->moves++;
		exit(0);
	}
	else if (info->map[info->y_player][info->x_player] == '1'
		|| info->map[info->y_player][info->x_player] == 'E')
		info->x_player -= 1;
	else
	{
		mlx_clear_window(info->mlx_ptr, info->mlx_win);
		if (info->map[info->y_player][info->x_player] == 'C')
			info->n_collect -= 1;
		info->map[info->y_player][info->x_player] = 'P';
		info->map[info->y_player][info->x_player - 1] = '0';
		info->moves++;
		enemy_anime(info);
		map_drawin(info);
	}
}

void	player_s(t_info *info)
{
	player_update_image('s', info);
	if ((info->map[info->y_player][info->x_player] == 'E'
		&& info->n_collect == 0)
		|| (info->map[info->y_player][info->x_player] == 'N'))
	{
		mlx_clear_window(info->mlx_ptr, info->mlx_win);
		info->map[info->y_player][info->x_player + 1] = '0';
		info->moves++;
		exit(0);
	}
	else if (info->map[info->y_player][info->x_player] == '1' ||
			info->map[info->y_player][info->x_player] == 'E')
		info->x_player += 1;
	else
	{
		mlx_clear_window(info->mlx_ptr, info->mlx_win);
		if (info->map[info->y_player][info->x_player] == 'C')
			info->n_collect -= 1;
		info->map[info->y_player][info->x_player] = 'P';
		info->map[info->y_player][info->x_player + 1] = '0';
		info->moves++;
		enemy_anime(info);
		map_drawin(info);
	}
}
