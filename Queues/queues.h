#ifndef QUEUE_H
#define QUEUE_H

#include "user.h"

/* A single node in the queue's linked list */
typedef struct QueueNode {
    User data;               /* the user stored at this node */
    struct QueueNode* next;  /* pointer to the next node */
} QueueNode;

/* The queue itself: tracks head and tail of the linked list */
typedef struct {
    QueueNode* head;
    QueueNode* tail;
} Queue;

/* Sets up an empty queue (head/tail = NULL) */
void queue_init(Queue* q);

/* Returns 1 if the queue has no nodes, 0 otherwise */
int queue_is_empty(const Queue* q);

/* Adds a user to the back of the queue. Returns 0 on success, non-zero on failure */
int queue_enqueue(Queue* q, User user);

/* Removes the user at the front of the queue and copies it into *outUser.
   Returns 0 on success, non-zero if the queue was empty */
int queue_dequeue(Queue* q, User* outUser);

/* Randomly generates `count` users and enqueues them.
   Returns 0 on success, non-zero on failure (e.g. bad arguments or alloc failure) */
int queue_enqueue_random_users(Queue* q, int count);

#endif