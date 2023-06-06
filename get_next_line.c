/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:08:54 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/06/06 18:07:47 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char *str)
{
	char	*line;
	int	i;
	int	line_len;

	i = 0;
	line_len = 0;
	while (str[line_len] && str[line_len] != '\n')
		line_len++;
	if (str[line_len] == '\n')
		line_len++;
	line = malloc((line_len + 1) * sizeof(char));
	if (line)
	{
		while (i < line_len)
		{
			line[i] = str[i];
			i++;
		}
		if (str[i] == '\n')
		{
			line[i] = str[i];
			i++;
		}
		line[i] = '\0';
	}
	free (str);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	int		bytes_read;
	char		*temp;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (backup)
	{
		line = ft_strdup(backup);
		free(backup);
	}
//'	if (ft_strchr(line, '\n'))
//'	{
//'		line = get_line(line);
//'		backup = ft_strchr(line, '\n');
//'		backup++;
//'		backup = ft_strdup(backup);
//'		return (line);
//'	}
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		printf("Bytes read: %d\n", bytes_read);
		if (bytes_read == 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
		printf("Line joined: %s\n", line);
		if (ft_strchr(buffer, '\n'))
		{
			line = get_line(line);
			temp = ft_strchr(buffer, '\n');
			temp++;
			if (*temp != '\0')
			{
				backup = ft_strdup(temp);
//				printf("Backup: %s\n", backup);
			}
			break ;
		}
	}
	free(buffer);
	return (line);
}
