/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:08:54 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/06/05 15:11:40 by tmina-ni         ###   ########.fr       */
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
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	char		*temp;
	int		bytes_read;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (backup != NULL)
		temp = ft_strdup(backup);
	line = NULL;
//	printf("Backup returned: %s\n", line);
	if (ft_strchr(backup, '\n'))
	{
		backup = ft_strchr(backup, '\n');
		backup++;
		return (line);
	}
	while (1)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (buffer == NULL)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
//		printf("Bytes read: %d\n", bytes_read);
		if (bytes_read == 0)
		{
//			free(line);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
//		printf("Buffer: %s\n", buffer);
		//complete line
		temp = ft_strjoin(temp, buffer);
//		printf("Line joined: %s\n", line);
		//check for backup
		if (ft_strchr(buffer, '\n'))
		{
			line = get_line(temp);
			free (temp);
			backup = ft_strchr(buffer, '\n');
			backup++;
//			backup = ft_memmove(backup, ft_strchr(buffer, '\n'), BUFFER_SIZE);
//			printf("Backup: %s\n", backup);
			break ;
		}
		free (buffer);
	}
	printf("Final line: %s\n", line);
	return (line);
}
