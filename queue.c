#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
        if (q == NULL) return 1;
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
        /* TODO: put a new process to queue [q] */
        if(q->size == MAX_QUEUE_SIZE){
                printf("queue is full\n");
                return;
        }
        if(q == NULL){
                printf("queue is NULL\n");
                return;          
        }
         if(proc == NULL){
                printf("process doesn't exist\n");
                return;
        }
        printf("before add %d", q->size);
        q->proc[q->size] = proc;
        q->size = q -> size + 1;
        printf("after add%d", q->size);
}

struct pcb_t * dequeue(struct queue_t * q) {
        /* TODO: return a pcb whose prioprity is the highest
         * in the queue [q] and remember to remove it from q
         * */
        
        if(q == NULL){
                printf("queue is NULL\n");
                return NULL;
        }
        if(q->size == 0){
            printf("queue is empty \n");
            return NULL;
        }

        struct pcb_t* max_priority = q->proc[0];
        int  max_priority_pcb = q->proc[0]->priority;
        int max_priority_pos = 0;
         // search the highest priority process in the queue
        for(int idx = 1; idx < q->size; idx++){
            if(q->proc[idx]->priority > max_priority){
                max_priority = q->proc[idx]->priority;
                max_priority_pcb = q->proc[idx];
                max_priority_pos = idx;
            }
        }
        for(int i = max_priority_pos; i < q->size - 1; i++){
                q->proc[i] = q->proc[i+1];
        }
        q->size = q->size - 1;
	return max_priority;
}

