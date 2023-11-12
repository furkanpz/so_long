/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuyar <fuyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:46:16 by fuyar             #+#    #+#             */
/*   Updated: 2023/11/12 16:50:14 by fuyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	f_fill(char **tab, t_point size, int row, int col)
{
	if (row < 0 || col < 0)
		return ;
	if (row >= size.y || col >= size.x)
		return ;
	if (tab[row][col] == '8' || tab[row][col] == '1')
		return ;
	tab[row][col] = '8';
	f_fill(tab, size, row - 1, col);
	f_fill(tab, size, row + 1, col);
	f_fill(tab, size, row, col - 1);
	f_fill(tab, size, row, col + 1);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	f_fill(tab, size, begin.y, begin.x);
}
