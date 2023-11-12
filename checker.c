/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuyar <fuyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:41:17 by fuyar             #+#    #+#             */
/*   Updated: 2023/11/12 16:57:10 by fuyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkall(t_map *s, t_chr *chr)
{
	int	y;
	int	x;

	y = -1;
	while (++y < s->mapy)
	{
		x = 0;
		while (x < s->mapx)
		{
			if (s->map[y][x] == 'E')
				chr->e += 1;
			if (s->map[y][x] == 'P')
				chr->player += 1;
			if (s->map[y][x] == 'C')
				chr->map->collsize += 1;
			x++;
		}
	}
	if ((chr->map->collsize > 0 && chr->player == 1) && chr->e == 1)
		return (1);
	else
		return (0);
}

int	checkall2(t_map *s, t_chr *chr)
{
	int	y;
	int	x;

	y = -1;
	while (++y < s->mapy)
	{
		x = 0;
		while (x < s->mapx)
		{
			if (!ft_strchr("1", s->map[y][x]) && (y == 0 || y == s->mapy - 1))
				return (0);
			if (!ft_strchr("10PEC", s->map[y][x]) && !(y == 0 || y == s->mapy))
				return (0);
			if (s->map[y][x] == 'P')
			{
				chr->charx = x;
				chr->chary = y;
			}
			x++;
		}
	}
	return (1);
}

int	checkall3(t_map *s, t_chr *chr)
{
	int	y;
	int	x;

	y = -1;
	while (++y < s->mapy)
	{
		x = 0;
		while (x < s->mapx)
		{
			if (ft_strchr("PEC", s->map[y][x]))
				return (0);
			if (x == chr->map->mapx - 1 && chr->map->map[y][x] != '1')
				return (0);
			if (x == 0 && chr->map->map[y][x] != '1')
				return (0);
			if (x >= chr->map->mapx)
				return (0);
			x++;
		}
		if (s->map[y][x] != '\0')
			return (0);
	}
	return (1);
}

void	ft_goflood(int x, int y, t_chr *chr, char **map)
{
	t_point	size;
	t_point	start;

	size.x = x;
	size.y = y;
	start.x = chr->charx;
	start.y = chr->chary;
	flood_fill(map, size, start);
}

void	mapcheck(char *mappath, t_chr *chr)
{
	t_map	*s;
	int		ret;

	s = get_map(mappath);
	ret = checkall(s, chr);
	if (ret == 0)
	{
		freemap(s);
		errorm('m', chr);
	}
	ret = checkall2(s, chr);
	if (ret == 0)
	{
		freemap(s);
		errorm('m', chr);
	}
	ft_goflood(s->mapx, s->mapy, chr, s->map);
	ret = checkall3(s, chr);
	if (ret == 0)
	{
		freemap(s);
		errorm('m', chr);
	}
	freemap(s);
}
