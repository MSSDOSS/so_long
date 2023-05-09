/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:26:22 by hel-haia          #+#    #+#             */
/*   Updated: 2023/05/09 01:23:47 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_av(char *av)
{
	int i;

	i = 0;
	if (!av)
		return (0);
	while (av[i])
		i++;
	i -= 4;
	if (av[i] == '.' && av[i + 1] == 'b' && av[i + 2] == 'e' && av[i + 3] == 'r')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*win_ptr;

	if (ac != 2)
		return (0);
	if (check_av(av[1]))
	{
		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, 640, 480, "so_long");// mlx_key_hook(vars.win, key_hook, &vars);
		mlx_loop(mlx_ptr);
	}
	return (0);
}
