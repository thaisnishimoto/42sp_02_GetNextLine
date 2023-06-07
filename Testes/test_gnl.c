/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:00:56 by tmina-ni          #+#    #+#             */
/*   Updated: 2023/06/07 18:05:45 by tmina-ni         ###   ########.fr       */
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
//	char	buffer1[1000] = "123\n";
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
	int	i;
	char	*line = NULL;
	char    *expected[] = {"1st line.\n", "2nd line.\n"};

	printf("\n-----------------\n");
	printf(" TEST 1: 2 lines");
	printf("\n-----------------\n");
	i = 0;
	fd = open("file.txt", O_RDWR);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("RETURNED LINE: %s", line);
		mu_assert_string_eq(expected[i++], line);
		printf("\n");
		free(line);
	}
	close (fd);
}

MU_TEST(int_no_nl)
{
	int	fd;
	char	*line;
	char	*expected = {"01234567890123456789012345678901234567890"};

	fd = open("41_no_nl.txt", O_RDWR | O_CREAT, 0777);
	if (fd < 0)
		printf("%s\n", "File did not open");
	printf("\n-----------------\n");
	printf(" TEST 2: int no nl");
	printf("\n-----------------\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("RETURNED LINE: %s\n\n", line);
		mu_assert_string_eq(expected, line);
		free(line);	
	}
	if (close(fd) == 0)
		printf("%s\n", "File closed");
}

//MU_TEST(just_nl)
//{
//	int	fd;
//	int	i;
//	char	*line;
//	char	expected[5] = {"\n", "\n", "\n", "\n", "\n"};
//
//	fd = open("just_nl.txt", O_RDWR | O_CREAT, 0777);
//	if (fd < 0)
//		printf("%s\n", "File did not open");
//	if (write(fd, "\n\n\n\n\n", 5) == -1)
//		printf("%s", "Write unsuccessful");
//	printf("\n-----------------\n");
//	printf(" TEST 3: just nl");
//	printf("\n-----------------\n");
//	i = 0;
//	while ((line = get_next_line(fd)) != NULL)
//	{
//		printf("RETURNED LINE: %s\n\n", line);
//		mu_assert_string_eq(expected[i++], line);
//		free(line);	
//	}
//	if (close(fd) == 0)
//		printf("%s\n", "File closed");
//}

MU_TEST_SUITE(test_suite)
{
//	MU_RUN_TEST(file_manipulation);
	MU_RUN_TEST(funtion_should_read_one_line);
	MU_RUN_TEST(int_no_nl);
//	MU_RUN_TEST(just_nl);
}

int	main(void)
{
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
