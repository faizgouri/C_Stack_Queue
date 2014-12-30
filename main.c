#include "stack.h"
#include "queue.h"
#include "data.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{

	if(argc < 2)
	{
		printf("Num args is less\n");
		exit(1);
	}
	int i = 0;
 	struct stack *s = createStack();
	for(i = 0; i < strlen(argv[1]); i++)
	{
		pushStack(s, createDataNumeral(argv[1][i]));
	}
	//printStack(s);
	printf("%d\n",convertRomanNumeralStack(s));

	//printf("size = %d\n", sizeStack(s));
	struct queue *q = createQueue();
	for(i = 0; i < strlen(argv[1]); i++)
	{
		pushQueue(q, createDataNumeral(argv[1][i]));
	}
	//printQueue(q);
	printf("%d\n", convertRomanNumeralQueue(q));
	cleanStack(s);
	cleanQueue(q);
	return 0;
}
