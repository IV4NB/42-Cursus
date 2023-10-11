#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("test.txt", O_RDONLY);
    while ((str = get_next_line(fd)) != NULL)
		printf("%s", str);
	free(str);
	return (0);
}