/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:08:54 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/06/06 00:30:17 by tmina-ni         ###   ########.fr       */
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
	free (str);
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
	line = NULL;
//	if (backup == NULL)
//		backup = ft_strdup("");
//	line = ft_strdup(backup);
//	printf("Backup returned: %s\n", line);
//	if (ft_strchr(backup, '\n'))
//	{
//		temp = ft_strchr(backup, '\n');
//		free (backup);
//		backup = temp++;
//		return (line);
//	}
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		printf("Bytes read: %d\n", bytes_read);
		if (bytes_read == 0)
		{
//			free(line);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
//		printf("Buffer: %s\n", buffer);
		//complete line
		line = ft_strjoin(line, buffer);
//		printf("Line joined: %s\n", line);
		//check for backup
		if (ft_strchr(buffer, '\n'))
		{
			line = get_line(line);
//			backup = ft_memmove(backup, ft_strchr(buffer, '\n'), BUFFER_SIZE);
//			backup++;
			//backup = ft_strdup(backup);
//			printf("Backup: %s\n", backup);
		//	free (buffer);
			break ;
		}
	}
	free(buffer);
//	printf("Final line: %s\n", line);
	return (line);
}
