/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuyar <fuyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:45:21 by fuyar             #+#    #+#             */
/*   Updated: 2023/11/12 17:02:30 by fuyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freemap(t_map *map)
{
	int	i;

	i = 0;
	while (i <= map->mapy)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}

int	closebutton(t_chr *chr)
{
	freemap(chr->map);
	free(chr->game);
	free(chr->img);
	mlx_destroy_window(chr->game->m, chr->game->mw);
	ft_printf("Successfully Closed\n");
	exit(0);
}

void	onlyexit(char c)
{
	if (c == 'm')
		ft_printf("Map Error\n");
	if (c == 't')
		ft_printf("Texture Error\n");
	if (c == 's')
		ft_printf("Congratulations on collecting all the cheeses\n");
	if (c == 'e')
		ft_printf("Successfully Closed\n");
	exit(0);
}

void	errorm(char c, t_chr *chr)
{
	if (c == 'm')
		ft_printf("Map Error\n");
	if (c == 't')
		ft_printf("Texture Error\n");
	if (c == 's')
		ft_printf("Congratulations on collecting all the cheeses\n");
	if (c == 'e')
		ft_printf("Successfully Closed\n");
	freemap(chr->map);
	if (c != 'm' && c != 't')
	{
		free(chr->game);
		free(chr->img);
	}
	if (c != 'm' && c != 't')
		mlx_destroy_window(chr->game->m, chr->game->mw);
	exit(0);
}
