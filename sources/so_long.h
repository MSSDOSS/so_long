/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:31:14 by hel-haia          #+#    #+#             */
/*   Updated: 2023/05/31 03:15:01 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define ZR "assets/zombi_right.xpm"
# define ZL "assets/zombi_left.xpm"
# define BW "assets/blue_brick.xpm"
# define OMC "assets/oldman_collect.xpm"
# define BB "assets/black_back.xpm"
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

typedef struct s_info
{
	void	*mlx_ptr;
	void	*mlx_win;
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
}	t_info;

char	*get_next_line(int fd);
void	infos_init(t_info *info);
int		map_drawin(t_info *info);
int		valid_path(char **v_path);
int		map_check(t_info *info);
void	keys_manage(t_info *info);
char	**map_read(char *path);
void	player_q(t_info *info);
void	player_z(t_info *info);
void	player_d(t_info *info);
void	player_s(t_info *info);
void	ft_check_permissions(t_info *info);

#endif
