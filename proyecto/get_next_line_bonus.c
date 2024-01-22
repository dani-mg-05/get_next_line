/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damedina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:32:38 by damedina          #+#    #+#             */
/*   Updated: 2023/12/30 13:54:07 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*free_ptr(char *str, char *tmp)
{
	if (str)
		free(str);
	if (tmp)
		free(tmp);
	return (0);
}

char	*read_buffer_size(int fd, char *str)
{
	char	*tmp;
	int		bytes_read;

	tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
	{
		free (str);
		str = 0;
		return (0);
	}
	bytes_read = 1;
	while (!ft_strchr(str, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free_ptr(str, tmp));
		tmp[bytes_read] = '\0';
		str = ft_strjoin(str, tmp);
		if (!str)
			return (free_ptr(str, tmp));
	}
	free(tmp);
	return (str);
}

char	*get_line_from_str(char *str)
{
	char	*ret;
	int		i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		ret = (char *)malloc((i + 2) * sizeof(char));
	else
		ret = (char *)malloc((i + 1) * sizeof(char));
	if (!ret)
		return (0);
	i = -1;
	while (str[++i] != '\n' && str[i] != '\0')
		ret[i] = str[i];
	if (str[i] == '\n')
		ret[i] = str[i];
	else
		i--;
	ret[i + 1] = '\0';
	return (ret);
}

char	*new_str(char *str)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (free_ptr(str, 0));
	ret = (char *)malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (!ret)
		return (free_ptr(str, ret));
	j = 0;
	while (str[++i] != '\0')
		ret[j++] = str[i];
	ret[j] = '\0';
	free(str);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (0);
	str[fd] = read_buffer_size(fd, str[fd]);
	if (!str[fd])
		return (0);
	ret = get_line_from_str(str[fd]);
	if (!ret)
	{
		free(str[fd]);
		str[fd] = 0;
		return (0);
	}
	str[fd] = new_str(str[fd]);
	return (ret);
}
