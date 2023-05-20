/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:31:14 by hel-haia          #+#    #+#             */
/*   Updated: 2023/05/18 22:49:49 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define D2R "textures/devil2Right.xpm"
# define D2L "textures/devil2Left.xpm"
# define DHW "textures/devil_house_wall.xpm"
# define DFR "textures/heart_fruit.xpm"
# define DF "textures/stars_back.xpm"
# define DEX "textures/devil_exit1.xpm"
# define ESC 53
# define UP 126
# define LEFT 123
# define DOWN 125
# define RIGHT 124
# define Z 6
# define Q 12
# define S 1
# define D 2

typedef struct da_data
{
	void	*player;
	void	*space;
	void	*wall;
	void	*collect;
	void	*exit;
	char	**lmap;
	void	*window;
	void	*con_id;
	int		m_width;
	int		m_height;
	int		img_width;
	int		img_height;
	int		n_collect;
	int		n_player;
	int		n_exit;
	int		x_player;
	int		y_player;
	int		moves;
}	t_data;

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str );
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	ft_putstr(char *s);
int		parsing_lmap(t_data *data);
void	initialize_the_struct(t_data *data);
int		draw_m(t_data *data);
void	free_koulchi(char **kharita);
int		exit_game(t_data *map);
int		keys(int n_key, t_data *map);
void	player_q(t_data *data);
void	player_z(t_data *data);
void	player_d(t_data *data);
void	player_s(t_data *data);
void	lhook(t_data *map);

#endif
