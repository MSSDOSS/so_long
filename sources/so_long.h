/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:31:14 by hel-haia          #+#    #+#             */
/*   Updated: 2023/05/30 06:02:22 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win;
	char	**map;
	void	*space;
	void	*wall;
	void	*player;
	void	*collect;
	void	*exit;
	int		map_w;
	int		map_h;
	int		img_w;
	int		img_h;
	int		n_collect;
	int		n_player;
	int		n_exit;
	int		x_player;
	int		y_player;
	int		moves;
}	t_data;

# define D2R "assets/zombi_right.xpm"
# define D2L "assets/zombi_left.xpm"
# define DHW "assets/blue_brick.xpm"
# define DFR "assets/zombie_fruit.xpm"
# define DF "assets/black_back.xpm"
# define DEX "assets/purple_exit.xpm"
# define KEY_ESC 53
# define KEY_Z 6
# define KEY_Q 12
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124

char	*get_next_line(int fd);
int		draw_the_map(t_data *data);
void	initialize_the_struct(t_data *data);
char	**ft_read_the_map(char *path);
int		valid_path(char **v_path);
int		map_checker(t_data *data);
void	controller(t_data *data);
void	player_q(t_data *data);
void	player_z(t_data *data);
void	player_d(t_data *data);
void	player_s(t_data *data);
void	ft_check_permissions(t_data *data);

#endif
