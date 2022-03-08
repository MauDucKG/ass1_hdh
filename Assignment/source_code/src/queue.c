#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	

	if(q->size < MAX_QUEUE_SIZE)
	{
		q->proc[q->size] = proc;
		q->size++;
	}
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */

	int max = 0;
	int max_i = 0;

	if (q->size == 0)
		return NULL;

	for (int i = 0; i < q->size; ++i){
		if (q->proc[i]->priority >= max)
		{
			max = q->proc[i]->priority;
			max_i = i;
		}
	}

	struct pcb_t * temp_proc = (struct pcb_t *)malloc(sizeof(struct pcb_t));	
	temp_proc = q->proc[max_i];
	q->proc[max_i] = q->proc[q->size - 1];
	q->size = q->size - 1;

	return temp_proc;
}

