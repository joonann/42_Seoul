#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd1;

	fd1 = open("./big_line_no_nl", O_RDONLY);

	printf("1result : %s\n", get_next_line(fd1));
	printf("2result : %s\n", get_next_line(fd1));
	printf("3result : %s\n", get_next_line(fd1));
	printf("4result : %s\n", get_next_line(fd1));
	printf("5result : %s\n", get_next_line(fd1));
	printf("6result : %s\n", get_next_line(fd1));
	close(fd1);

	return (0);
}
