/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:18:53 by hel-haia          #+#    #+#             */
/*   Updated: 2023/01/21 19:18:55 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n--)
		*(s1++) = *(s2++);
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	len1;
	size_t	len2;

	if (!s1)
	{
		s1 = malloc(1);
		if (!(s1))
			return (NULL);
		s1[0] = 0;
	}
	if (s1 || s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		join = (char *)malloc(len1 + len2 + 1);
		if (!join)
			return (join);
		ft_memcpy(join, s1, len1);
		ft_memcpy(join + len1, s2, len2 +1);
		free(s1);
		return (join);
	}
	return (NULL);
}
