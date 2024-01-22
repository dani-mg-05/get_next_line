/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:09:56 by damedina          #+#    #+#             */
/*   Updated: 2023/10/11 13:13:24 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *s, int c)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != (unsigned char)c && s[i] != '\0')
		i++;
	if (s[i] == '\0' && (unsigned char)c != '\0')
		return (0);
	return (&s[i]);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	idst;
	size_t	isrc;
	size_t	size_dst;

	size_dst = ft_strlen(dst);
	if (dstsize < ft_strlen(dst) || (dstsize == 0 && dst[0] == '\0'))
		return (dstsize + ft_strlen(src));
	idst = size_dst;
	isrc = 0;
	while (idst < dstsize - 1 && src[isrc] != '\0')
	{
		dst[idst] = src[isrc];
		idst++;
		isrc++;
	}
	dst[idst] = '\0';
	return (ft_strlen(src) + size_dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		if (!s1)
		{
			free (s1);
			s1 = NULL;
			return (NULL);
		}
		s1[0] = '\0';
	}
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
	{
		free(s1);
		return (0);
	}
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, ft_strlen(s1) + ft_strlen (s2) + 1);
	free(s1);
	return (str);
}
