/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuyar <fuyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:09:23 by fuyar             #+#    #+#             */
/*   Updated: 2023/10/18 11:16:29 by fuyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	a;

	if (!str)
		return (NULL);
	a = ft_strlen(str);
	while (a >= 0)
	{
		if (*str == (char)c)
			return (str);
		a--;
		str++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		a;
	int		b;
	char	*dst;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	dst = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
		return (NULL);
	a = -1;
	while (s1[++a])
		dst[a] = s1[a];
	b = -1;
	while (s2[++b])
		dst[a + b] = s2[b];
	dst[a + b] = '\0';
	free(s1);
	return (dst);
}
