/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:08:54 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/06/07 19:44:20 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_until_nl(int fd, char *buffer, char *line, char *backup)
{
	int	bytes_read;

	if (backup)
	{
		line = ft_strdup(backup);
		//free(backup);
//		backup = NULL;
	}
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
//		printf("Bytes read: %d\n", bytes_read);
		if (bytes_read <= 0)
		{
			if (line)
				return (line);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
//		printf("Line joined: %s\n", line);
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
	char	*temp;
	char	*remainder;

	remainder = NULL;
	temp = ft_strchr(buffer, '\n');
	temp++;
	if (*temp != '\0')
		remainder = ft_strdup(temp);
	return (remainder);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	line = read_until_nl(fd, buffer, line, backup);
	if (backup)
	{
		free(backup);
		backup = NULL;
	}
	if (ft_strlen(line) == 0)
	{
		free(buffer);
		return (NULL);
	}
	if (line)
	{
		if (ft_strchr(line, '\n'))
		{
			line = get_line(line);
			backup = save_remainder(buffer);
		}
	}
	free(buffer);
	return (line);
}

//int main(void)
//{
//    int        fd;
//    char    *line;
//
//    fd = open("41_with_nl.txt", O_RDONLY);
//    while ((line = get_next_line(fd)) != NULL)
//    {
//        printf("%s", line);
//        free(line);
//    }
//    close(fd);
//    return (0);
//}	
