/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:39:08 by hel-haia          #+#    #+#             */
/*   Updated: 2023/05/16 23:12:26 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_update_image(char key, t_data *data)
{
	mlx_destroy_image(data->con_id, data->player);
	if (key == 'q')
		data->player = mlx_xpm_file_to_image
			(data->con_id, D2R, &data->img_width, &data->img_height);
	else if (key == 'z')
		data->player = mlx_xpm_file_to_image
			(data->con_id, D2L, &data->img_width, &data->img_height);
	else if (key == 'd')
		data->player = mlx_xpm_file_to_image
			(data->con_id, D2R, &data->img_width, &data->img_height);
	else if (key == 's')
		data->player = mlx_xpm_file_to_image
			(data->con_id, D2L, &data->img_width, &data->img_height);
}

void	player_q(t_data *data)
{
	player_update_image('q', data);
	if (data->lmap[data->y_player][data->x_player] == 'E' && data->n_collect == 0)
	{
		mlx_clear_window(data->con_id, data->window);
		data->lmap[data->y_player + 1][data->x_player] = '0';
		data->moves++;
		draw_m(data);
	}
	else if (data->lmap[data->y_player][data->x_player] == '1'
		|| data->lmap[data->y_player][data->x_player] == 'E')
		data->y_player += 1;
	else
	{
		mlx_clear_window(data->con_id, data->window);
		if (data->lmap[data->y_player][data->x_player] == 'C')
			data->n_collect -= 1;
		data->lmap[data->y_player][data->x_player] = 'P';
		data->lmap[data->y_player + 1][data->x_player] = '0';
		data->moves++;
		draw_m(data);
	}
}

void	player_z(t_data *data)
{
	player_update_image('z', data);
	if (data->lmap[data->y_player][data->x_player] == 'E' && data->n_collect == 0)
	{
		mlx_clear_window(data->con_id, data->window);
		data->lmap[data->y_player - 1][data->x_player] = '0';
		data->moves++;
		draw_m(data);
	}
	else if (data->lmap[data->y_player][data->x_player] == '1'
		|| data->lmap[data->y_player][data->x_player] == 'E')
		data->y_player -= 1;
	else
	{
		mlx_clear_window(data->con_id, data->window);
		if (data->lmap[data->y_player][data->x_player] == 'C')
			data->n_collect -= 1;
		data->lmap[data->y_player][data->x_player] = 'P';
		data->lmap[data->y_player - 1][data->x_player] = '0';
		data->moves++;
		draw_m(data);
	}
}

void	player_d(t_data *data)
{
	player_update_image('d', data);
	if (data->lmap[data->y_player][data->x_player] == 'E' && data->n_collect == 0)
	{
		mlx_clear_window(data->con_id, data->window);
		data->lmap[data->y_player][data->x_player - 1] = '0';
		data->moves++;
		draw_m(data);
	}
	else if (data->lmap[data->y_player][data->x_player] == '1'
		|| data->lmap[data->y_player][data->x_player] == 'E')
		data->x_player -= 1;
	else
	{
		mlx_clear_window(data->con_id, data->window);
		if (data->lmap[data->y_player][data->x_player] == 'C')
			data->n_collect -= 1;
		data->lmap[data->y_player][data->x_player] = 'P';
		data->lmap[data->y_player][data->x_player - 1] = '0';
		data->moves++;
		draw_m(data);
	}
}

void	player_s(t_data *data)
{
	player_update_image('s', data);
	if (data->lmap[data->y_player][data->x_player] == 'E' && data->n_collect == 0)
	{
		mlx_clear_window(data->con_id, data->window);
		data->lmap[data->y_player][data->x_player + 1] = '0';
		data->moves++;
		draw_m(data);
	}
	else if (data->lmap[data->y_player][data->x_player] == '1' ||
			data->lmap[data->y_player][data->x_player] == 'E')
		data->x_player += 1;
	else
	{
		mlx_clear_window(data->con_id, data->window);
		if (data->lmap[data->y_player][data->x_player] == 'C')
			data->n_collect -= 1;
		data->lmap[data->y_player][data->x_player] = 'P';
		data->lmap[data->y_player][data->x_player + 1] = '0';
		data->moves++;
		draw_m(data);
	}
}