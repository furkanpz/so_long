/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuyar <fuyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:09:55 by fuyar             #+#    #+#             */
/*   Updated: 2023/11/12 16:04:45 by fuyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>

typedef struct s_map
{
	char	**map;
	int		mapy;
	int		mapx;
	int		collsize;
}				t_map;

typedef struct s_img
{
	void	*b;
	void	*c;
	void	*en;
	void	*e;
	void	*m;
	void	*s;
}				t_img;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_game{
	void	*m;
	void	*mw;
	int		width;
	int		height;
}				t_game;

typedef struct s_chr
{
	int		charx;
	int		chary;
	int		exitx;
	int		exity;
	int		coll;
	int		e;
	int		player;
	int		moves;
	t_img	*img;
	t_map	*map;
	t_game	*game;
}				t_chr;

int		linecheck(int fd);
void	mapcheck(char *mappath, t_chr *chr);
t_map	*get_map(char *mappath);
void	add_image(t_chr *character);
void	if_w(t_chr *chr, int x, int y);
void	if_s(t_chr *chr, int x, int y);
void	if_d(t_chr *chr, int x, int y);
void	if_a(t_chr *chr, int x, int y);
void	setimage(t_chr *character);
void	errorm(char c, t_chr *chr);
void	freemap(t_map *map);
void	onlyexit(char c);
void	flood_fill(char **tab, t_point size, t_point begin);
int		closebutton(t_chr *chr);
void	checkimage(t_chr *chr);

#endif