#include <stdio.h>
#include <stdlib.h>
#include "queues.h"

/* Initialize an empty queue */
void queue_init(Queue* q) {
    q->head = NULL;
    q->tail = NULL;
}

/* Queue is empty if it has no head node */
int queue_is_empty(const Queue* q) {
    return q->head == NULL;
}

/* Remaining function implementations added in upcoming commits */