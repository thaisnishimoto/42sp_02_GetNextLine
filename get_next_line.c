/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:08:54 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/05/31 23:18:16 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer; //buffer to input string read
	char	*line;
	int	i;
	int	j;
	int	bytes;
	static char	*backup;

	j = 0;
	i = 0;
	line = malloc(100 * sizeof(char));
	if (line == NULL)
		return (NULL);
	if (backup)
	{
		if (ft_strchr(backup, '\n'))
		{
			while (backup[i] != '\n')
			{
				line[j] = backup[i];
				j++;
				i++;
			}
			backup = ft_strchr(backup, '\n');
			return (line);
		}
		else
		{
			while (backup[i])
			{
				line[j] = backup[i];
				j++;
				i++;
			}
		}
	}
//	printf("Backup len: %zu", ft_strlen(backup));
//	while (backup[i])
//	{
//		if (backup[i] != '\0')
//		{	
//			str[j] = backup[i];
//			i++;
//			j++;
//		}
//		else
//		{
//			str[j] = backup[i++];
//			backup = ft_strdup(&backup[i]);
//			return (str);
//		}
//	}
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	while (1)
	{
		bytes = (read(fd, buffer, BUFFER_SIZE));
		printf("Bytes read: %d\n", bytes);
		if (bytes == 0)
			return (NULL);
		buffer[BUFFER_SIZE] = '\0';
		printf("Buffer: %s\n", buffer);
		i = 0;
		while(i < BUFFER_SIZE)
		{
			if (buffer[i] != '\n')
			{
				line[j] = buffer[i];
				j++;
				i++;
			}
			else
			{
				line[j] = buffer[i];
				j++;
				line[j] = '\0';
				break;
			}
		}
		if (buffer[i] == '\n')
		{	
			i++;
			break;
		}
	}
	printf("Line: %s\n", line);
	backup = ft_strdup(&buffer[i]);
	free(buffer);
	printf("Backup: %s\n", backup);
	return (line);
}
