/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuyar <fuyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:03:27 by fuyar             #+#    #+#             */
/*   Updated: 2023/11/12 15:48:12 by fuyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkimage(t_chr *chr)
{
	int	fd;

	fd = open("textures/s.xpm", O_RDONLY);
	if (fd == -1)
		errorm('t', chr);
	fd = open("textures/b.xpm", O_RDONLY);
	if (fd == -1)
		errorm('t', chr);
	fd = open("textures/c.xpm", O_RDONLY);
	if (fd == -1)
		errorm('t', chr);
	fd = open("textures/e.xpm", O_RDONLY);
	if (fd == -1)
		errorm('t', chr);
	fd = open("textures/en.xpm", O_RDONLY);
	if (fd == -1)
		errorm('t', chr);
	fd = open("textures/m.xpm", O_RDONLY);
	if (fd == -1)
		errorm('t', chr);
}

void	setimage(t_chr *chr)
{
	int		width;
	int		height;
	t_game	*game;

	game = chr->game;
	chr->img->s = mlx_xpm_file_to_image(game->m, \
	"textures/s.xpm", &width, &height);
	chr->img->b = mlx_xpm_file_to_image(game->m, \
	"textures/b.xpm", &width, &height);
	chr->img->m = mlx_xpm_file_to_image(game->m, \
	"textures/m.xpm", &width, &height);
	chr->img->c = mlx_xpm_file_to_image(game->m, \
	"textures/c.xpm", &width, &height);
	chr->img->en = mlx_xpm_file_to_image(game->m, \
	"textures/en.xpm", &width, &height);
	chr->img->e = mlx_xpm_file_to_image(game->m, \
	"textures/e.xpm", &width, &height);
}

void	setimage2(t_img *img, t_chr *chr, int x, int y)
{
	t_game	*game;

	game = chr->game;
	if (chr->map->map[y][x] == '1')
		mlx_put_image_to_window(game->m, game->mw, img->b, x * 64, y * 64);
	if (chr->map->map[y][x] == '0')
		mlx_put_image_to_window(game->m, game->mw, img->s, x * 64, y * 64);
	if (chr->map->map[y][x] == 'P')
	{
		mlx_put_image_to_window(game->m, game->mw, img->m, x * 64, y * 64);
		chr->charx = x;
		chr->chary = y;
	}
	if (chr->map->map[y][x] == 'C')
		mlx_put_image_to_window(game->m, game->mw, img->c, x * 64, y * 64);
	if ((chr->exitx == x && chr->exity == y) && chr->map->map[y][x] == 'P')
		mlx_put_image_to_window(game->m, game->mw, img->e, x * 64, y * 64);
	else if (chr->map->map[y][x] == 'E' || ((chr->exitx == x \
	&& chr->exity == y) && chr->map->map[y][x] == '0'))
	{
		mlx_put_image_to_window(game->m, game->mw, img->en, x * 64, y * 64);
		chr->map->map[y][x] = 'E';
		chr->exitx = x;
		chr->exity = y;
	}
}

void	add_image(t_chr *chr)
{
	t_map	*map;
	int		x;
	int		y;

	x = 0;
	y = 0;
	map = chr->map;
	while (y < map->mapy)
	{
		x = -1;
		while (++x <= map->mapx)
		{
			if (map->map[y][x] == '1')
				setimage2(chr->img, chr, x, y);
			if (map->map[y][x] == '0')
				setimage2(chr->img, chr, x, y);
			if (map->map[y][x] == 'P')
				setimage2(chr->img, chr, x, y);
			if (map->map[y][x] == 'C')
				setimage2(chr->img, chr, x, y);
			if (map->map[y][x] == 'E')
				setimage2(chr->img, chr, x, y);
		}
		y++;
	}
}
