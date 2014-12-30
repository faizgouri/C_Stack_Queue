#include "stack.h"
#include "dlinklist.h"
#include "data.h"

struct stack* createStack()
{
  struct stack *s = malloc(sizeof(struct stack));
  s->stk = createDLinkedList();
  return s;
}

void pushStack(struct stack *s,struct data *dta)
{
	addFront(s->stk, dta);
}

struct data* topStack(struct stack *s)
{
	return (getFront(s->stk));
}

void popStack(struct stack *s)
{
	free(topStack(s));
	removeFront(s->stk);
}

void lazyPopStack(struct stack *s)
{
	removeFront(s->stk);
}

int isEmptyStack(struct stack *s)
{

	return isEmpty(s->stk);

}

void printStack(struct stack *s)
{
	// create a temp stack
	struct stack *temp = createStack();
	// Take each element on by one, print them, push them to temp stack and then pop from the origianl stack(use lazy pop, because we need the data)
	while(!isEmptyStack(s))
	{
		struct data *dta = topStack(s);
		printData(dta);
		pushStack(temp, dta);
		lazyPopStack(s);
	}
	// pop each element from temp stack and push them to original stack
	while(!isEmptyStack(temp))
	{
		struct data *dta = topStack(temp);
		pushStack(s, dta);
		lazyPopStack(temp);
	}
	// clean temp stack
	cleanStack(temp);
}

int sizeStack(struct stack *s)
{

	struct stack *temp = createStack();
	int size = 0;
	while(!isEmptyStack(s))
	{
		struct data *dta = topStack(s);
		pushStack(temp, dta);
		lazyPopStack(s);
		size++;
	}
	while(!isEmptyStack(temp))
	{
		struct data *dta = topStack(temp);
		pushStack(s, dta);
		lazyPopStack(temp);
	}
	cleanStack(temp);
	return size;
}

void cleanStack(struct stack *s)
{
	while(!isEmptyStack(s))
	{
		popStack(s);
	}
	free(s->stk);
	free(s);
}

int convertRomanNumeralStack(struct stack *s)
{
        int result  = 0; // to store final result
        int num = 0; // to store numeric equivalent of the current element in stack
        int max = 0; // to store maximum number so far in the stack
        char ch = '\0';
	int invalid = 0; // flag to check whether Roman number is valid or not, invalid = 1 means invalid

	// create a temp stack
        struct stack *temp = createStack();

	// Take all elements of stack one by by and calculate the result 
	while(!isEmptyStack(s))
        {
                struct data *dta = topStack(s);
                // current character in stack
		ch = dta->numeral;
		// calculate corresponding numeric value
                switch(ch)
                {
                        case 'I' :      num = 1;
                                        break;
                        case 'V' :      num = 5;
                                        break;
                        case 'X' :      num = 10;
                                        break;
                        case 'L' :      num = 50;
                                        break;
                        case 'C' :      num = 100;
                                        break;
                        case 'D' :      num = 500;
                                        break;
                        case 'M' :      num = 1000;
                                        break;
                        default  :      printf("Invalid Number\n");
					invalid = 1;
                                        break;
                }
		// if number is more than or equal to max, add it to the result and update max with num
		if(num >= max)
                {
                        result = result + num;
			max = num;
                }
		//otherwise subtract current number from result
                else
                {
                        result = result - num;
                }
                pushStack(temp, dta);
                lazyPopStack(s);
        }
        while(!isEmptyStack(temp))
        {
                struct data *dta = topStack(temp);
                pushStack(s, dta);
                lazyPopStack(temp);
        }
        cleanStack(temp);
	// If Number was invalid, return 0
	if(invalid)
	{
		return 0;
	}
	// otherwise return result
        return result;
}
