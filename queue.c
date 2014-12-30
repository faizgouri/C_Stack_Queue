#include "queue.h"
#include "data.h"

int convertRomanNumeralQueue(struct queue *q)
{
	int result  = 0; // To store result
        int num = 0; // to store numeric value of current element in queue
        int sum = 0;
	int prev = 0;
        char ch = '\0';
	int invalid = 0; // flag to check whether Roman number is valid or not, 1 means invalid, 0 means valid 
     	struct queue *temp = createQueue();

        while(!isEmptyQueue(q))
        {
                struct data *dta = topQueue(q);
                // current character in queue
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
		// if number is equal to previous number, add it to the sum
		if(num == prev)
		{
			sum = sum + num;
		}
		// if number is larger than prev element in queue than update result and sum as given below
                else if(num > prev)
                {
                        result = result - sum;
			sum = num;
                }
		// otherwise updateas below 
                else
                {
                        result = result + sum;
			sum = num;
                }
		prev = num;

		pushQueue(temp, dta);
                lazyPopQueue(q);
        }
	result = result + sum;

        while(!isEmptyQueue(temp))
        {
                struct data *dta = topQueue(temp);
                pushQueue(q, dta);
                lazyPopQueue(temp);
        }
        cleanQueue(temp);
	// if number was invalid, return 0
	if(invalid)
	{
		return 0;
	}
	// otherwise return result
        return result;
}

struct queue* createQueue()
{
  struct queue *q = malloc(sizeof(struct queue));
  q->que = createDLinkedList();
  return q;
}

void pushQueue(struct queue *q,struct data *dta)
{
	addBack(q->que, dta);
}

struct data* topQueue(struct queue *q)
{
	return (getFront(q->que));
}

void popQueue(struct queue *q)
{
	free(getFront(q->que)); // faiz
	removeFront(q->que);
}

void lazyPopQueue(struct queue *q)
{
	removeFront(q->que);
}

int isEmptyQueue(struct queue *q)
{
	return (isEmpty(q->que));
}

void printQueue(struct queue *q)
{
	struct queue *temp = createQueue();
	while(!isEmptyQueue(q))
	{
		struct data *dta = topQueue(q);
		printData(dta);
		pushQueue(temp, dta);
		lazyPopQueue(q);
	}
	while(!isEmptyQueue(temp))
        {
		struct data *dta = topQueue(temp);
                pushQueue(q, dta);
                lazyPopQueue(temp);
        }
	cleanQueue(temp);
}

int sizeQueue(struct queue *q)
{

	int size = 0;
	struct queue *temp = createQueue();
        while(!isEmptyQueue(q))
        {
                struct data *dta = topQueue(q);
                size++;
                pushQueue(temp, dta);
                lazyPopQueue(q);
        }
        while(!isEmptyQueue(temp))
        {
                struct data *dta = topQueue(temp);
                pushQueue(q, dta);
                lazyPopQueue(temp);
        }
        cleanQueue(temp);

	return size;
}

void cleanQueue(struct queue *q)
{

	while(!isEmptyQueue(q))
	{
		popQueue(q);
	}
	free(q->que);
	free(q);
}
