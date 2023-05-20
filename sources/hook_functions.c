/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:49:13 by hel-haia          #+#    #+#             */
/*   Updated: 2023/05/18 02:41:53 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

int	exit_game(t_data *map)
{
	// free_koulchi(map->lmap);
	mlx_destroy_image(map->con_id, map->wall);
	mlx_destroy_image(map->con_id, map->space);
	mlx_destroy_image(map->con_id, map->player);
	mlx_destroy_image(map->con_id, map->collect);
	mlx_destroy_image(map->con_id, map->exit);
	mlx_destroy_image(map->con_id, map->window);
	// free(map->con_id);
	// map->con_id = NULL;
	exit(0);
	return (0);
}

static void	game_updates(int keycode, t_data *data)
{
	if (keycode == Q || keycode == UP)
	{
		data->y_player -= 1;
		player_q(data);
	}
	else if (keycode == Z || keycode == DOWN)
	{
		data->y_player += 1;
		player_z(data);
	}
	else if (keycode == D || keycode == RIGHT)
	{
		data->x_player += 1;
		player_d(data);
	}
	else if (keycode == S || keycode == LEFT)
	{
		data->x_player -= 1;
		player_s(data);
	}
}

int	keys(int n_key, t_data *map)
{
	if (n_key == ESC)
		exit_game(map);
	else
	{
		game_updates(n_key, map);
		ft_putnbr(map->moves);
		ft_putstr("\n");
	}
	return (0);
}

void	lhook(t_data *map)
{
	printf("\n||%d||\n", 80);
	mlx_hook(map->window, 2, 0, keys, map);
	printf("\n||%d||\n", 90);
	mlx_hook(map->window, 2, 0, exit_game, map);
	printf("\n||%d||\n", 100);
	mlx_hook(map->window, 2, 0, draw_m, map);
	printf("\n||%d||\n", 1000);
}
