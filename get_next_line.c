/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:08:54 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/05/29 17:37:54 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 42

//size_t	ft_linelen(int fd);

char	*get_next_line(int fd)
{
//	char	buff[100];
	char	*buffer; //buffer to input string

	buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (buffer)
	{
		read(fd, buffer, BUFFER_SIZE);
	}	
	return (buffer);
}
