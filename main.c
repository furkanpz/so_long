/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuyar <fuyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:48:21 by fuyar             #+#    #+#             */
/*   Updated: 2023/11/12 17:02:34 by fuyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_input(int keycode, t_chr *chr)
{
	int	x;
	int	y;

	x = chr->charx;
	y = chr->chary;
	if (keycode == 13)
		if_w(chr, x, y);
	else if (keycode == 0)
		if_a(chr, x, y);
	else if (keycode == 2)
		if_d(chr, x, y);
	else if (keycode == 1)
		if_s(chr, x, y);
	else if (keycode == 53)
		errorm('e', chr);
	add_image(chr);
	return (1);
}

void	returnchr(t_chr *gchr, char *mappath)
{
	gchr->map = get_map(mappath);
	if (!gchr->map)
		onlyexit('m');
	gchr->player = 0;
	gchr->e = 0;
	gchr->coll = 0;
	gchr->moves = 0;
	mapcheck(mappath, gchr);
	gchr->game = malloc(sizeof(t_game));
	gchr->game->m = mlx_init();
	gchr->game->mw = mlx_new_window(gchr->game->m, gchr->map->mapx \
	* 64, (gchr->map->mapy) * 64, "so_long");
	gchr->img = malloc(sizeof(t_img));
	checkimage(gchr);
	setimage(gchr);
	add_image(gchr);
}

int	testber(char *str)
{
	int	i;
	int	b;
	int	c;

	i = 4;
	b = ft_strlen(str);
	c = b - 4;
	while (b >= c)
	{
		if (str[b] == ".ber"[i])
		{
			i--;
			if (b == 0)
				return (0);
			else if (str[b - 1] == '/' || (str[b - 1] == '.' \
			&& (str[b - 2] == '/' )))
				return (0);
		}
		b--;
	}
	if (i == -1)
		return (1);
	return (0);
}

int	main(int ac, char *av[])
{
	t_chr	*gchr;
	int		c;

	if (ac == 2)
	{
		c = testber(av[1]);
		if (c != 1)
			onlyexit('m');
		gchr = malloc(sizeof(t_chr));
		returnchr(gchr, av[1]);
		mlx_hook(gchr->game->mw, 2, 0, get_input, gchr);
		mlx_hook(gchr->game->mw, 17, 0, closebutton, gchr);
		mlx_loop(gchr->game->m);
	}
	else
	{
		ft_printf("1 Arguments You Must Enter!");
		exit(0);
	}
}
