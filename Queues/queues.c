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

/* Add a new node holding `user` to the tail of the queue */
int queue_enqueue(Queue* q, User user) {
    QueueNode* node = (QueueNode *)malloc(sizeof(QueueNode));
    if (node == NULL) {
        return 1; /* allocation failed */
    }

    node->data = user;
    node->next = NULL;

    if (queue_is_empty(q)) {
        q->head = node; /* first node becomes both head and tail */
        q->tail = node;
    }
    else {
        q->tail->next = node; /* link onto the current tail */
        q->tail = node;
    }

    return 0;
}

/* Remove the head node and hand its data back via outUser */
int queue_dequeue(Queue* q, User* outUser) {
    if (queue_is_empty(q)) {
        return 1; /* nothing to dequeue */
    }

    QueueNode* oldHead = q->head;
    *outUser = oldHead->data;

    q->head = oldHead->next;
    if (q->head == NULL) {
        q->tail = NULL; /* queue is now empty, reset tail too */
    }

    free(oldHead);
    return 0;
}

/* Remaining function implementations added in upcoming commits */