/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:26:22 by hel-haia          #+#    #+#             */
/*   Updated: 2023/05/30 06:11:01 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**ft_read_the_map(char *path)
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

int	argv_checker(char *av)
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

void	start_the_game(t_data data, char **v_path)
{
	if (map_check(&data) && valid_path(v_path))
	{
		initialize_the_struct(&data);
		draw_the_map(&data);
		mlx_loop(data.mlx_ptr);
	}
	else if (data.map)
	{
		ft_putstr("Error:\nSomthing is going wrong... try to fix it.");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	**v_path;

	if (argc == 2 && argv_checker(argv[1]) == 1)
	{
		v_path = ft_read_the_map(argv[1]);
		data.map = ft_read_the_map(argv[1]);
		start_the_game(data, v_path);
	}
	else
	{
		ft_putstr("Error:\ntwo arguments required, ");
		ft_putstr("the second must have (.ber) extension");
		exit(1);
	}
	return (0);
}
