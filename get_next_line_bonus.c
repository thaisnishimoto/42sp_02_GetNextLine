/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:08:54 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/06/10 15:05:09 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_until_nl(int fd, char *buffer, char *line, char *backup)
{
	int	bytes_read;

	if (backup)
		line = ft_strdup(backup);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			if (line)
				return (line);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
		if (ft_strchr(line, '\n'))
			break ;
	}
	return (line);
}

static char	*get_line(char *str)
{
	char	*line;
	int		i;
	int		line_len;

	i = 0;
	line_len = 0;
	while (str[line_len] && str[line_len] != '\n')
		line_len++;
	if (str[line_len] == '\n')
		line_len++;
	line = malloc((line_len + 1) * sizeof(char));
	if (line)
	{
		ft_memmove(line, str, line_len);
		line[line_len] = '\0';
	}
	free(str);
	return (line);
}

static char	*save_remainder(char *buffer)
{
	int		i;
	int		len;
	char	*remainder;

	i = 0;
	len = 0;
	remainder = NULL;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	len = ft_strlen(buffer) - i;
	if (buffer[i] != '\0')
	{
		remainder = malloc((len + 1) * sizeof(char));
		if (remainder)
		{
			ft_memmove(remainder, &buffer[i], len);
			remainder[len] = '\0';
		}
	}
	return (remainder);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*backup[MAX_FD];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	line = NULL;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	line = read_until_nl(fd, buffer, line, backup[fd]);
	if (backup[fd])
	{
		free(backup[fd]);
		backup[fd] = NULL;
	}	
	if (line && ft_strchr(line, '\n'))
	{
			backup[fd] = save_remainder(line);
			line = get_line(line);
	}
	free(buffer);
	return (line);
}
