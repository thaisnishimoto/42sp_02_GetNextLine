/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:00:56 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/05/31 23:17:21 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "get_next_line.h"

char    *get_next_line(int fd);

MU_TEST(file_manipulation)
{
	int	fd;
	int	i = 0;
	ssize_t	bytes;
	char	buffer1[1000] = "1st line.\n2nd line.\n3rd line.\n";
	char	buffer2[1000];

	fd = open("file.txt", O_RDWR | O_CREAT, 0777);
	if (fd < 0)
		printf("%s\n", "File did not open");
	else
	{
		printf("%s | fd= %d\n", "File opened", fd);
		if (write(fd, buffer1, strlen(buffer1)) == -1)
			printf("%s", "Write unsuccessful");
		else
		{
			lseek(fd, 0, SEEK_SET);
			bytes = read(fd, buffer2, strlen(buffer1));
			if (bytes == -1)
				printf("%s", "Read unsuccessful");
			else
			{
				printf("Bytes read: %ld\n", bytes);
				printf("\nContent of file:\n");
				while (buffer2[i])
					write(1, &buffer2[i++], 1);	
			}
		}
		if (close(fd) == 0)
			printf("%s\n", "File closed");
	}
}

MU_TEST(funtion_should_read_one_line)
{
	int	fd;
	char	*line;

	printf("\n TEST 1:\n");
	fd = open("file.txt", O_RDWR);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("RETURNED LINE: %s\n", line);
		free(line);	
	}
//	line = get_next_line(fd);
//	printf("%s\n", line);
//	free(line);	
//	line = get_next_line(fd);
//	printf("%s\n", line);
//	free(line);	
//	line = get_next_line(fd);
//	printf("%s\n", line);
//	free(line);	
//	line = get_next_line(fd);
//	printf("%s\n", line);
//	free(line);	
}

MU_TEST_SUITE(test_suite)
{
	MU_RUN_TEST(file_manipulation);
	MU_RUN_TEST(funtion_should_read_one_line);
}

int	main(void)
{
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
