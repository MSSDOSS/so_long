/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:26:22 by hel-haia          #+#    #+#             */
/*   Updated: 2023/05/31 03:20:59 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**map_read(char *path)
{
	int		fd;
	char	*line;
	char	*joiner;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	joiner = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		joiner = ft_strjoin(joiner, line);
		free(line);
	}
	map = ft_split(joiner, '\n');
	free(joiner);
	close(fd);
	return (map);
}

int	check_extension(char *av)
{
	int	i;

	if (!av)
		return (0);
	i = ft_strlen(av);
		i--;
	if (av[i] == 'r' && av[i - 1] == 'e' && av[i - 2] == 'b'
		&& av [i - 3] == '.')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_info	info;
	char	**v_path;

	if (ac == 2 && check_extension(av[1]) == 1)
	{
		v_path = map_read(av[1]);
		info.map = map_read(av[1]);
		if (map_check(&info) && valid_path(v_path))
		{
			infos_init(&info);
			map_drawin(&info);
			mlx_loop(info.mlx_ptr);
		}
		else if (info.map)
		{
			ft_putstr("Error:\nINVALID MAP");
			exit(1);
		}
	}
	else
	{
		ft_putstr("Error:\n2 arguments required & second chould be with .ber");
		exit(1);
	}
	return (0);
}
