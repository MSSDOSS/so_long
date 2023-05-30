/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:49:13 by hel-haia          #+#    #+#             */
/*   Updated: 2023/05/30 05:44:58 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	exit_the_game(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->space);
	mlx_destroy_image(data->mlx_ptr, data->wall);
	mlx_destroy_image(data->mlx_ptr, data->player);
	mlx_destroy_image(data->mlx_ptr, data->collect);
	mlx_destroy_image(data->mlx_ptr, data->exit);
	mlx_destroy_window(data->mlx_ptr, data->win);
	data->mlx_ptr = NULL;
	exit(0);
	return (0);
}

void	game_events(int keycode, t_data *data)
{
	if (keycode == KEY_Q || keycode == KEY_UP)
	{
		data->y_player -= 1;
		player_q(data);
	}
	else if (keycode == KEY_Z || keycode == KEY_DOWN)
	{
		data->y_player += 1;
		player_z(data);
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		data->x_player += 1;
		player_d(data);
	}
	else if (keycode == KEY_S || keycode == KEY_LEFT)
	{
		data->x_player -= 1;
		player_s(data);
	}
}

int	keypress(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		exit_the_game(data);
	else
	{
		game_events(keycode, data);
		mlx_string_put(data->mlx_ptr, data->win, data->map_w /2 - 64, 0, 0xFF0000, "MOVED: ");
		mlx_string_put(data->mlx_ptr, data->win, data->map_w /2, 0, 0x00FF00, ft_itoa(data->moves));
	}
	return (0);
}

void	enemy_anime(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->enemy);
	data->enemy = mlx_xpm_file_to_image(data->mlx_ptr, EN, &data->img_w, &data->img_h);
	if(data->n_collect == 10)
		data->enemy = mlx_xpm_file_to_image(data->mlx_ptr, EN2, &data->img_w, &data->img_h);
	else if(data->n_collect == 9)
		data->enemy = mlx_xpm_file_to_image(data->mlx_ptr, EN3, &data->img_w, &data->img_h);
	else if(data->n_collect == 8)
		data->enemy = mlx_xpm_file_to_image(data->mlx_ptr, EN4, &data->img_w, &data->img_h);
	else if(data->n_collect == 7)
		data->enemy = mlx_xpm_file_to_image(data->mlx_ptr, EN5, &data->img_w, &data->img_h);
	else if(data->n_collect == 6)
		data->enemy = mlx_xpm_file_to_image(data->mlx_ptr, D2L, &data->img_w, &data->img_h);
	else if(data->n_collect == 5)
		data->enemy = mlx_xpm_file_to_image(data->mlx_ptr, D2L, &data->img_w, &data->img_h);
	else if(data->n_collect == 4)
		data->enemy = mlx_xpm_file_to_image(data->mlx_ptr, D2L, &data->img_w, &data->img_h);
	else if(data->n_collect == 3)
		data->enemy = mlx_xpm_file_to_image(data->mlx_ptr, D2L, &data->img_w, &data->img_h);
	else if (data->n_collect == 2)
		data->enemy = mlx_xpm_file_to_image(data->mlx_ptr, D2R, &data->img_w, &data->img_h);
	else if (data->n_collect == 1)
		data->enemy = mlx_xpm_file_to_image(data->mlx_ptr, D2L, &data->img_w, &data->img_h);
}

void	controller(t_data *data)
{
	draw_the_map(data);
	mlx_hook(data->win, 2, 0, keypress, data);
	mlx_hook(data->win, 17, 0, exit_the_game, data);
}
