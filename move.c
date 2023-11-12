/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuyar <fuyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:57:45 by fuyar             #+#    #+#             */
/*   Updated: 2023/11/12 15:02:02 by fuyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	if_w(t_chr *chr, int x, int y)
{
	if (chr->map->map[y - 1][x] == '0' || (chr->map->map[y - 1][x] == 'C'))
	{
		if (chr->map->map[y - 1][x] == 'C')
			chr->coll += 1;
		chr->map->map[y][x] = '0';
		chr->map->map[y - 1][x] = 'P';
		chr->moves += 1;
		ft_printf("Step: %i\n", chr->moves);
	}
	else if (chr->map->map[y - 1][x] == 'E')
	{
		chr->moves += 1;
		ft_printf("Step: %i\n", chr->moves);
		if (chr->map->collsize == chr->coll)
			errorm('s', chr);
		else
		{
			chr->map->map[y][x] = '0';
			chr->map->map[y - 1][x] = 'P';
		}
	}
}

void	if_s(t_chr *chr, int x, int y)
{
	if (chr->map->map[y + 1][x] == '0' || (chr->map->map[y + 1][x] == 'C'))
	{
		if (chr->map->map[y + 1][x] == 'C')
			chr->coll += 1;
		chr->map->map[y][x] = '0';
		chr->map->map[y + 1][x] = 'P';
		chr->moves += 1;
		ft_printf("Step: %i\n", chr->moves);
	}
	else if (chr->map->map[y + 1][x] == 'E')
	{
		chr->moves += 1;
		ft_printf("Step: %i\n", chr->moves);
		if (chr->map->collsize == chr->coll)
			errorm('s', chr);
		else
		{
			chr->map->map[y][x] = '0';
			chr->map->map[y + 1][x] = 'P';
		}
	}
}

void	if_d(t_chr *chr, int x, int y)
{
	if (chr->map->map[y][x + 1] == '0' || chr->map->map[y][x + 1] == 'C')
	{
		if (chr->map->map[y][x + 1] == 'C')
			chr->coll += 1;
		chr->map->map[y][x] = '0';
		chr->map->map[y][x + 1] = 'P';
		chr->moves += 1;
		ft_printf("Step: %i\n", chr->moves);
	}
	else if (chr->map->map[y][x + 1] == 'E')
	{
		chr->moves += 1;
		ft_printf("Step: %i\n", chr->moves);
		if (chr->map->collsize == chr->coll)
			errorm('s', chr);
		else
		{
			chr->map->map[y][x] = '0';
			chr->map->map[y][x + 1] = 'P';
		}
	}
}

void	if_a(t_chr *chr, int x, int y)
{
	if (chr->map->map[y][x - 1] == '0' || chr->map->map[y][x - 1] == 'C')
	{
		if (chr->map->map[y][x - 1] == 'C')
			chr->coll += 1;
		chr->map->map[y][x] = '0';
		chr->map->map[y][x - 1] = 'P';
		chr->moves += 1;
		ft_printf("Step: %i\n", chr->moves);
	}
	else if (chr->map->map[y][x - 1] == 'E')
	{
		chr->moves += 1;
		ft_printf("Step: %i\n", chr->moves);
		if (chr->map->collsize == chr->coll)
			errorm('s', chr);
		else
		{
			chr->map->map[y][x] = '0';
			chr->map->map[y][x - 1] = 'P';
		}
	}
}
