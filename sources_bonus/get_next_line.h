/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:18:32 by hel-haia          #+#    #+#             */
/*   Updated: 2023/01/23 19:14:04 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

char	*ft_strjoin(char *s1, char *s2);
char	*ft_remainder(char *tmp);
char	*ft_reline(char *tmp);
char	ft_check_newline(char *tmp);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);

#endif
