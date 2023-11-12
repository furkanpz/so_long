/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuyar <fuyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:10:28 by fuyar             #+#    #+#             */
/*   Updated: 2023/11/04 19:16:58 by fuyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*ft_strchr(char *str, int c);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_getleft(char *dst);
char	*ft_getline(char *dst);
char	*ft_readline(int fd, char *dst);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

#endif