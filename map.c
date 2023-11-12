/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuyar <fuyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:54:00 by fuyar             #+#    #+#             */
/*   Updated: 2023/11/12 16:25:34 by fuyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	linecheck(int fd)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(1);
	str[0] = 1;
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	free(str);
	return (i);
}

int	add_map(t_map *map, int fd)
{
	int	i;

	i = 0;
	while (i < map->mapy)
	{
		map->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	if (!map->map[0])
	{
		freemap(map);
		return (0);
	}
	map->mapx = ft_strlen(map->map[0]);
	map->mapy -= 1;
	return (1);
}

t_map	*get_map(char *mappath)
{
	int		i;
	int		fd;
	t_map	*map;

	map = malloc(sizeof(t_map));
	fd = open(mappath, O_RDONLY);
	map->mapy = linecheck(fd);
	if (map->mapy <= 2 || map->mapy > 22)
	{
		free(map);
		return (NULL);
	}
	map->map = malloc(sizeof(char *) * map->mapy + 1);
	map->collsize = 0;
	close(fd);
	fd = open(mappath, O_RDONLY);
	i = add_map(map, fd);
	if (i == 0)
		return (NULL);
	if (map->mapx > 40)
	{
		freemap(map);
		return (NULL);
	}
	return (map);
}
