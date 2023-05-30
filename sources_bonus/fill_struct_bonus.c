/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 01:25:12 by hel-haia          #+#    #+#             */
/*   Updated: 2023/05/31 00:24:05 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_permissions(t_info *info)
{
	if (info->player == NULL || info->space == NULL
		|| info->wall == NULL || info->collect == NULL || info->exit == NULL)
	{
		ft_putstr("Error:\nCheck your assets permissions.");
		exit(1);
	}
}

void	infos_init(t_info *info)
{
	int	i;

	info->mlx_ptr = mlx_init();
	info->map_w = ft_strlen(info->map[0]) * 50;
	i = 0;
	while (info->map[i] != (void *)0)
		i++;
	info->map_h = i * 50;
	info->mlx_win = mlx_new_window
		(info->mlx_ptr, info->map_w, info->map_h, "so_long");
	info->space = mlx_xpm_file_to_image
		(info->mlx_ptr, BB, &info->img_w, &info->img_h);
	info->wall = mlx_xpm_file_to_image
		(info->mlx_ptr, BW, &info->img_w, &info->img_h);
	info->player = mlx_xpm_file_to_image
		(info->mlx_ptr, ZR, &info->img_w, &info->img_h);
	info->collect = mlx_xpm_file_to_image
		(info->mlx_ptr, OMC, &info->img_w, &info->img_h);
	info->exit = mlx_xpm_file_to_image
		(info->mlx_ptr, DEX, &info->img_w, &info->img_h);
	info->enemy = mlx_xpm_file_to_image
		(info->mlx_ptr, EN, &info->img_w, &info->img_h);
	info->moves = 0;
	ft_check_permissions(info);
	keys_manage(info);
}

void	call_func(t_info *info, int x, int y)
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
	else if (info->map[y][x] == 'N')
		put_enemy(info, x, y);
}
