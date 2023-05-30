/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:08:54 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/05/30 17:53:29 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer; //buffer to input string read
	char	*str;
	static char	*temp;
	int	i;
	int	j;
//	while (temp[i] != '\n')
//	{
//		if (temp[i] != '\0')
//			i++;
//		else
//			break;
//	}
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	str = malloc(100 * sizeof(char));
	if (buffer == NULL || str == NULL)
		return (NULL);
//		while (read(fd, buffer, BUFFER_SIZE))
//		{
//			printf("Buffer: %s\n", buffer);
//			if (ft_strchr(buffer, '\n') == NULL);
//		}
//	}
	j = 0;
	while (1)
	{
		read(fd, buffer, BUFFER_SIZE);
		printf("Buffer: %s\n", buffer);
		i = 0;
		while(i < BUFFER_SIZE)
		{
			if (buffer[i] != '\n')
			{
				str[j] = buffer[i];
				j++;
				i++;
			}
			else
			{
				str[j] = buffer[i];
				j++;
				break;
			}
		}
		if (buffer[i] == '\n')
			break;
	}
//		while (buffer[i] != '\n')
//		{	
//			str[i] = buffer[i];
//			i++;
//		}
//		if (buffer[i] == '\n')
//		{
//			str[i] = buffer[i];
//			i++;
//		}
	str[j] = '\0';
	printf("Line: %s\n", str);
	temp = ft_strdup(&buffer[i]);
	free(buffer);
	printf("Backup: %s\n", temp);
	return (str);
}
