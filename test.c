#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int	id = fork();
	if (id != 0)
		fork();
	printf("hello choom\n");
	/*if (id == 0)
		printf("hello from child process\n");
	else
		printf("hello from parent process\n");
	*/
	return (0);
}
