/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:18:18 by hel-haia          #+#    #+#             */
/*   Updated: 2023/01/23 23:49:29 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_remainder(char *temp)
{
	size_t	len;
	size_t	total_len;
	char	*remainder;
	size_t	i;

	len = 0;
	i = ft_strlen(temp);
	while (temp[len] && temp[len] != '\n')
		len++;
	if (temp[len] == '\n')
		len++;
	if (len == i)
		return (free(temp), NULL);
	remainder = malloc(i - len + 1);
	if (!remainder)
		return (NULL);
	total_len = 0;
	while (temp[len])
		remainder[total_len++] = temp[len++];
	remainder[total_len] = '\0';
	free(temp);
	temp = NULL;
	return (remainder);
}

char	*ft_reline(char *temp)
{
	size_t	len;
	char	*line;

	len = 0;
	if (!temp[len])
		return (NULL);
	while (temp[len] && temp[len] != '\n')
		len++;
	line = malloc(len + 2);
	if (!line)
		return (NULL);
	len = 0;
	while (temp[len])
	{
		if (temp[len] == '\n')
		{
			line[len] = '\n';
			len++;
			break ;
		}
		line[len] = temp[len];
		len++;
	}
	line[len] = 0;
	return (line);
}

char	ft_check_newline(char *temp)
{
	int	i;

	i = 0;
	if (!temp)
		return ('N');
	while (temp[i])
	{
		if (temp[i] == '\n')
			return ('Y');
		i++;
	}
	return ('N');
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*temp;
	ssize_t		bytes;
	char		*returned_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE +1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (bytes != 0 && ft_check_newline(temp) == 'N')
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buffer), free(temp), temp = NULL, NULL);
		buffer[bytes] = 0;
		temp = ft_strjoin(temp, buffer);
	}
	returned_line = ft_reline(temp);
	temp = ft_remainder(temp);
	free(buffer);
	return (returned_line);
}
