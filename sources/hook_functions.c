/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:49:13 by hel-haia          #+#    #+#             */
/*   Updated: 2023/05/30 04:58:47 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	free_map(char **map)
// {
// 	int	i;

// 	i = 0;
// 	while (map[i] != (void *)0)
// 	{
// 		free(map[i]);
// 		i++;
// 	}
// 	free(map);
// 	map = NULL;
// }

int	exit_the_game(t_data *data)
{
	// free_map(data->map);
	mlx_destroy_image(data->mlx_ptr, data->space);
	mlx_destroy_image(data->mlx_ptr, data->wall);
	mlx_destroy_image(data->mlx_ptr, data->player);
	mlx_destroy_image(data->mlx_ptr, data->collect);
	mlx_destroy_image(data->mlx_ptr, data->exit);
	mlx_destroy_window(data->mlx_ptr, data->win);
	// free(data->mlx_ptr);
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
		ft_putstr("Moved ");
		ft_putnbr(data->moves);
		ft_putstr(" times\n");
	}
	return (0);
}

void	controller(t_data *data)
{
	mlx_hook(data->win, 2, 0, keypress, data);
	mlx_hook(data->win, 17, 0, exit_the_game, data);
	mlx_hook(data->win, 9, 0, draw_the_map, data);
}
