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
		line = ft_linedup(backup);
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
			free(line);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
//		printf("Buffer: %s\n", buffer);
		//complete line
		temp = ft_join_line(line, buffer);
		line = temp;
//		printf("Line joined: %s\n", line);
		//check for backup
		if (ft_strchr(buffer, '\n'))
		{
			backup = ft_memmove(backup, ft_strchr(buffer, '\n'), BUFFER_SIZE);
			backup++;
			//backup = ft_strdup(backup);
//			printf("Backup: %s\n", backup);
		//	free (buffer);
			break ;
		}
		free (buffer);
		buffer = NULL;
	}
	printf("Final line: %s\n", line);
	return (line);
}
