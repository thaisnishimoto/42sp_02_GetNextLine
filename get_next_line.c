/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:08:54 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/06/06 19:10:15 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char    *get_line(char *str)
{
    char    *line;
    int        i;
    int        line_len;

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

char    *get_next_line(int fd)
{
    char        *buffer;
    char        *line;
    int            bytes_read;
    char        *temp;
    static char    *backup;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    line = NULL;
    bytes_read = 1;
    if (backup)
    {
        line = ft_strdup(backup);
        free(backup);
    }
    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (buffer == NULL)
        return (NULL);
    while (bytes_read)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
        {
            free(buffer);
            if (line)
                return (line);
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        line = ft_strjoin(line, buffer);
        if (ft_strchr(buffer, '\n'))
        {
            line = get_line(line);
            temp = ft_strchr(buffer, '\n');
            temp++;
            if (*temp != '\0')
            {
                backup = ft_strdup(temp);
            }
            break ;
        }
    }
    free(buffer);
    return (line);
}

// int main(void)
// {
//     int        fd;
//     char    *line;

//     fd = open("int.txt", O_RDONLY);
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free(line);
//     }
//     close(fd);
//     return (0);
// }
