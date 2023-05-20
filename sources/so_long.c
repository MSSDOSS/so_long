/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:26:22 by hel-haia          #+#    #+#             */
/*   Updated: 2023/05/18 22:37:34 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	free_koulchi(char **kharita)
// {
// 	int	i;

// 	i = 0;
// 	while(kharita[i])
// 	{
// 		free(kharita[i]);
// 		i++;
// 	}
// 	free(kharita);
// 	kharita = NULL;
// }

// char	**read_map(char *file)
// {
// 	int		fd;
// 	char	*joiner;
// 	char	*line;
// 	char	*temp;
// 	char	**map;
	
// 	fd = open(file, O_RDONLY);
// 	if (fd == -1)
// 		return (0);
// 	joiner = ft_strdup("");
// 	joiner = NULL;
// 	if (!joiner)
// 		exit(1);
// 	while (1)
// 		{
// 			line = get_next_line(fd);
// 			if (!line)
// 				break ;
// 			temp = joiner;
// 			joiner = ft_strjoin(joiner, line);
// 			free(line);
// 		}
// 		map = ft_split(joiner, '\n');
// 		free(joiner);
// 		close(fd);
// 		return (map);
// }

void	get_map(char *str ,t_data *map){
	int i;
	int fd;
	i =0;
	map->lmap = malloc(sizeof(char *)*23);
	if (!map->lmap){
		printf("error\n");
		exit(1);
	}
	fd=open(str,O_RDONLY);
	map->lmap[i] = get_next_line(fd);;
	while (map->lmap[i])
	{
		i++;
		map->lmap[i]=get_next_line(fd);;
	}
	
	map->lmap[i]=NULL;
}

static int	check_av(char *av)
{
	int	i;

	i = 0;
	if (!av)
		return (0);
	while (av[i])
		i++;
	i -= 4;
	if (av[i] == '.' && av[i + 1] == 'b' && av[i + 2] == 'e'
		&& av[i + 3] == 'r')
		return (1);
	return (0);
}

// static void	star_game(t_data data, char **str)
// {
// 	if (parsing_lmap(data) && directions())
// 	{
		
// 	}
// 	else
// 	{
// 		ft_putstr("The Maaaaap Not Valid!!!");
// 		exit(1);
// 	}
// }

int	main(int ac, char **av)
{
	// void	*mlx_ptr;
	// void	*win_ptr;
	// char	**valid_road;
	t_data	map;

	// if (ac != 2)
	// {
	// 	ft_putstr("sorry!! you need to insert two arguments\n");
	// 	return (0);
	// }
	if (ac == 2 && check_av(av[1]))
	{
		// valid_road = read_map(av[1]);
		// map.lmap = read_map(av[1]);
		get_map(av[1] ,&map);
		// if (parsing_lmap(&map) != 0)
		// {
	// 		// free_koulchi(valid_road);
			initialize_the_struct(&map);
			printf("\n||%d||\n", 2000);
			draw_m(&map);
			printf("\n||%d||\n", 3000);
			mlx_loop(map.con_id);
		// }
		// else
		// {
		// 	if (map.lmap)
		// 		// free_koulchi(map.lmap);
		// 	ft_putstr("Error:\nSomthing is going wrong... try to fix it.");
		// 	exit(1);
		// }
			// mlx_ptr = mlx_init();
			// win_ptr = mlx_new_window(mlx_ptr, 640, 480, "so_long");
			// mlx_loop(mlx_ptr);
	}
	else
	{
		ft_putstr("ERROR\n");
		ft_putstr("the second arg need to be a file with (.ber) extension\n");
	}
	// exit(1);
	return (0);
}
