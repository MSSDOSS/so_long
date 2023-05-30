/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:49:13 by hel-haia          #+#    #+#             */
/*   Updated: 2023/05/31 00:02:46 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	exit_the_game(t_info *info)
{
	mlx_destroy_image(info->mlx_ptr, info->space);
	mlx_destroy_image(info->mlx_ptr, info->wall);
	mlx_destroy_image(info->mlx_ptr, info->collect);
	mlx_destroy_image(info->mlx_ptr, info->player);
	mlx_destroy_image(info->mlx_ptr, info->exit);
	mlx_destroy_image(info->mlx_ptr, info->enemy);
	mlx_destroy_window(info->mlx_ptr, info->mlx_win);
	info->mlx_ptr = NULL;
	exit(0);
	return (0);
}

void	game_events(int keycode, t_info *info)
{
	if (keycode == KEY_Q || keycode == KEY_UP)
	{
		info->y_player -= 1;
		player_q(info);
	}
	else if (keycode == KEY_Z || keycode == KEY_DOWN)
	{
		info->y_player += 1;
		player_z(info);
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		info->x_player += 1;
		player_d(info);
	}
	else if (keycode == KEY_S || keycode == KEY_LEFT)
	{
		info->x_player -= 1;
		player_s(info);
	}
}

int	keypress(int keycode, t_info *info)
{
	if (keycode == KEY_ESC)
		exit_the_game(info);
	else
	{
		game_events(keycode, info);
		mlx_string_put(info->mlx_ptr, info->mlx_win,
			info->map_w / 2 - 64, 0, 0xFF0000, "MOVED: ");
		mlx_string_put(info->mlx_ptr, info->mlx_win,
			info->map_w / 2, 0, 0x00FF00, ft_itoa(info->moves));
	}
	return (0);
}

void	enemy_anime(t_info *info)
{
	mlx_destroy_image(info->mlx_ptr, info->enemy);
	info->enemy = mlx_xpm_file_to_image
		(info->mlx_ptr, EN, &info->img_w, &info->img_h);
	if (info->n_collect == 7)
		info->enemy = mlx_xpm_file_to_image
			(info->mlx_ptr, EN2, &info->img_w, &info->img_h);
	else if (info->n_collect == 6)
		info->enemy = mlx_xpm_file_to_image
			(info->mlx_ptr, EN3, &info->img_w, &info->img_h);
	else if (info->n_collect == 5)
		info->enemy = mlx_xpm_file_to_image
			(info->mlx_ptr, EN4, &info->img_w, &info->img_h);
	else if (info->n_collect == 4)
		info->enemy = mlx_xpm_file_to_image
			(info->mlx_ptr, EN5, &info->img_w, &info->img_h);
	else if (info->n_collect == 3)
		info->enemy = mlx_xpm_file_to_image
			(info->mlx_ptr, EN2, &info->img_w, &info->img_h);
	else if (info->n_collect == 2)
		info->enemy = mlx_xpm_file_to_image
			(info->mlx_ptr, EN3, &info->img_w, &info->img_h);
	else if (info->n_collect == 1)
		info->enemy = mlx_xpm_file_to_image
			(info->mlx_ptr, EN4, &info->img_w, &info->img_h);
}

void	keys_manage(t_info *info)
{
	map_drawin(info);
	mlx_hook(info->mlx_win, 2, 0, keypress, info);
	mlx_hook(info->mlx_win, 17, 0, exit_the_game, info);
}
