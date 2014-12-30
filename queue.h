#include "dlinklist.h"
#include <stdlib.h>
#include "data.h"

struct queue
{
  struct dlinklist *que;

};
//allocate queue
struct queue* createQueue();
//push item onto the queue
void pushQueue(struct queue *q,struct data *dta);
//get item from top of queue, in order to avoid conflicting type with stack, using name as topQ
struct data* topQueue(struct queue *q);
//pop item from the queue
void popQueue(struct queue *q);
//test if queue is empty.  return 1 if empty and 0 is not
int isEmptyQueue(struct queue *q);
//print queue.  You have to print from the queue.  You can not call a print function from dlinklist
void printQueue(struct queue *q);
//get number of elements from queue
int sizeQueue(struct queue *q);
//clean queue memory
void cleanQueue(struct queue *q);
// pop one element from queue, but won't free memory occupied by data. (To be used for copying elements to temp Queue)
void lazyPopQueue(struct queue *q);
// Convert a Roman number into numeric
int convertRomanNumeralQueue(struct queue *q);
