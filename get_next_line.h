/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:08:54 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/06/02 20:15:41 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

#include <stdio.h> //printf
#include <stdlib.h> //malloc, free
#include <unistd.h> //write, read
#include <fcntl.h> //open, close
#include <string.h>

char	*get_next_line(int fd);
char	*ft_linedup(const char *s);
size_t	ft_linelen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_join_line(char *s1, char *s2);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42

#endif
