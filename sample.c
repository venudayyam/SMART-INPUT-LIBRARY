#include "smartinput.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

int main(void)
{
	unsigned short arr[MAX];

	for (int i=0; i<MAX; )
	{
		int temp;
		printf("arr[%d] : ",i);
		temp = get_ushort(arr+i);
		if (temp == FAILURE)
			fprintf(stderr,"error  : invalid input. try again..\n");
		else if (temp == EOF)
			exit(EXIT_FAILURE);
		else
			++i;
	}

	puts("\n\nLIST\n");
	for (int i=0; i<MAX; i++)
		printf("arr[%d] = %d\n",i,arr[i]);

	return 0;	
}
