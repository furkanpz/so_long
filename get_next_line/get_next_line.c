/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuyar <fuyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:11:45 by fuyar             #+#    #+#             */
/*   Updated: 2023/11/09 16:42:49 by fuyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readline(int fd, char *dst)
{
	int		i;
	char	*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	i = 1;
	while (!ft_strchr(dst, '\n') && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		dst = ft_strjoin(dst, buff);
	}
	free(buff);
	return (dst);
}

char	*ft_getline(char *dst)
{
	int		i;
	char	*ret;

	i = 0;
	if (!dst[i])
		return (NULL);
	while (dst[i] && dst[i] != '\n')
		i++;
	ret = malloc(sizeof(char) * (i + 2));
	if (!ret)
		return (NULL);
	i = 0;
	while (dst[i] && dst[i] != '\n')
	{
		ret[i] = dst[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_getleft(char *dst)
{
	int		i;
	int		c;
	char	*ret;

	i = 0;
	while (dst[i] != '\n' && dst[i])
		i++;
	if (!dst[i])
	{
		free(dst);
		return (NULL);
	}
	ret = malloc(sizeof(char) * (ft_strlen(dst) - i + 1));
	if (!ret)
		return (NULL);
	i++;
	c = 0;
	while (dst[i])
		ret[c++] = dst[i++];
	ret[c] = '\0';
	free(dst);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*dst;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	dst = ft_readline(fd, dst);
	if (!dst)
		return (NULL);
	str = ft_getline(dst);
	dst = ft_getleft(dst);
	return (str);
}
