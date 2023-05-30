/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:49:13 by hel-haia          #+#    #+#             */
/*   Updated: 2023/05/31 00:02:46 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_the_game(t_info *info)
{
	mlx_destroy_image(info->mlx_ptr, info->space);
	mlx_destroy_image(info->mlx_ptr, info->wall);
	mlx_destroy_image(info->mlx_ptr, info->player);
	mlx_destroy_image(info->mlx_ptr, info->collect);
	mlx_destroy_image(info->mlx_ptr, info->exit);
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
		ft_putstr("Moved ");
		ft_putnbr(info->moves);
		ft_putstr(" times\n");
	}
	return (0);
}

void	keys_manage(t_info *info)
{
	mlx_hook(info->mlx_win, 2, 0, keypress, info);
	mlx_hook(info->mlx_win, 17, 0, exit_the_game, info);
	mlx_hook(info->mlx_win, 9, 0, map_drawin, info);
}
