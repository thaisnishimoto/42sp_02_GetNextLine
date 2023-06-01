/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:08:54 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/06/01 18:26:19 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	char		line[100];
	char		*temp;
	int			i;
	int			j;
	size_t			buff_len;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	j = 0;
	i = 0;
//	line = malloc(100 * sizeof(char));
//	if (line == NULL)
//		return (NULL);
	if (backup)
	{
		if (ft_strchr(backup, '\n'))
		{
			while (backup[i] != '\n')
				line[j++] = backup[i++];
			line[j++] = backup[i++];
			line[j] = '\0';
			backup = ft_strchr(backup, '\n');
			backup++;
			return (line);
		}
		else
		{
			while (backup[i])
				line[j++] = backup[i++];
		}
	}
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	while (1)
	{
		if ((read(fd, buffer, BUFFER_SIZE)) == 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[BUFFER_SIZE] = '\0';
		printf("Buffer: %s\n", buffer);
		buff_len = printf("Buffer len: %zu\n", ft_strlen(buffer));
		i = 0;
//		if (ft_strchr(buffer, '\n'))
//			line = ft_strdup(buffer);
		while (i < BUFFER_SIZE)
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
				break ;
			}
		}
		if (buffer[i] == '\n')
		{	
			i++;
			break ;
		}
	}
	printf("Line: %s\n", line);
	backup = ft_strdup(&buffer[i]);
	free(buffer);
	printf("Backup: %s\n", backup);
	temp = ft_strdup(line);
	return (temp);
}
