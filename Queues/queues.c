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

/* Fills `username` with `len` random letters/digits + null terminator */
static void generate_random_username(char* username, int len) {
    static const char charset[] = "abcdefghijklmnopqrstuvwxyz0123456789";
    int i;

    for (i = 0; i < len; i++) {
        int idx = rand() % (sizeof(charset) - 1); /* -1 to exclude null terminator */
        username[i] = charset[idx];
    }
    username[len] = '\0';
}

/* Builds one random User: random username, level 1-60, random faction */
static User generate_random_user(void) {
    User u;

    generate_random_username(u.username, USERNAME_LEN);
    u.level = (rand() % 60) + 1;        /* 1 - 60 inclusive */
    u.faction = (Faction)(rand() % 3);  /* 0 = red, 1 = blue, 2 = green */

    return u;
}

int queue_enqueue_random_users(Queue* q, int count) {
    int i;

    if (q == NULL || count < 0) {
        return 1; /* invalid arguments */
    }

    for (i = 0; i < count; i++) {
        User u = generate_random_user();
        if (queue_enqueue(q, u) != 0) {
            return 1; /* enqueue failed (memory failure) */
        }
    }

    return 0;
}