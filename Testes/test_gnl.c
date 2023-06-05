/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:00:56 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/06/05 12:27:29 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "../get_next_line.h"

char    *get_next_line(int fd);

//MU_TEST(file_manipulation)
//{
//	int	fd;
//	int	i = 0;
//	ssize_t	bytes;
//	char	buffer1[1000] = "1st line.\n2nd line.\n3rd line.\n";
//	char	buffer2[1000];
//
//	fd = open("file.txt", O_RDWR | O_CREAT, 0777);
//	if (fd < 0)
//		printf("%s\n", "File did not open");
//	else
//	{
//		printf("%s | fd= %d\n", "File opened", fd);
//		if (write(fd, buffer1, strlen(buffer1)) == -1)
//			printf("%s", "Write unsuccessful");
//		else
//		{
//			lseek(fd, 0, SEEK_SET);
//			bytes = read(fd, buffer2, strlen(buffer1));
//			if (bytes == -1)
//				printf("%s", "Read unsuccessful");
//			else
//			{
//				printf("Bytes read: %ld\n", bytes);
//				printf("\nContent of file:\n");
//				while (buffer2[i])
//					write(1, &buffer2[i++], 1);	
//			}
//		}
//		if (close(fd) == 0)
//			printf("%s\n", "File closed");
//	}
//}

MU_TEST(funtion_should_read_one_line)
{
	int	fd;
	char	*line;

	printf("\n----------------\n");
	printf("\n TEST 1:\n");
	fd = open("file.txt", O_RDWR);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("RETURNED LINE: %s", line);
		free(line);	
	}
	close (fd);
}

//MU_TEST(no_nl)
//{
//	int	fd;
//	char	*line;
//
//	printf("\n----------------\n");
//	printf("\n TEST 2:\n");
//	fd = open("42_no_nl.txt", O_RDWR);
//	while ((line = get_next_line(fd)) != NULL)
//	{
//		printf("RETURNED LINE: %s\n\n", line);
//		free(line);	
//	}
//	close (fd);
//}
//}
//
//MU_TEST(empty_file)
//{
//	int	fd;
//	char	*line;
//
//	printf("\n----------------\n");
//	printf("\n TEST 3:\n");
//	fd = open("empty.txt", O_RDWR);
//	while ((line = get_next_line(fd)) != NULL)
//	{
//		printf("RETURNED LINE: %s\n\n", line);
//		free(line);	
//	}
//	if (line == NULL)
//		printf("RETURNED NULL");
//	close (fd);
//}
//}

MU_TEST_SUITE(test_suite)
{
//	MU_RUN_TEST(file_manipulation);
	MU_RUN_TEST(funtion_should_read_one_line);
//	MU_RUN_TEST(no_nl);
//	MU_RUN_TEST(empty_file);
}

int	main(void)
{
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
