/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 00:03:51 by hel-haia          #+#    #+#             */
/*   Updated: 2022/11/01 16:32:42 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen (s))
	{
		p = malloc (1);
		if (!p)
			return (NULL);
		*p = '\0';
		return (p);
	}
	if (len > ft_strlen (s + start))
		len = ft_strlen (s + start);
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (0);
	while (i < len)
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}
