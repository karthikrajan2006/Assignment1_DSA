#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queues.h"
#include "user.h"

int main(int argc, char* argv[]) {
    Queue q;
    int numUsers;
    int result;
    User dequeuedUser;

    /* Require exactly one command line argument: number of users to generate */
    if (argc != 2) {
        printf("Usage: %s <number_of_users>\n", argv[0]);
        return 1;
    }

    numUsers = atoi(argv[1]);
    if (numUsers <= 0) {
        printf("Error: number of users must be a positive integer.\n");
        return 1;
    }

    srand((unsigned int)time(NULL)); /* seed RNG so usernames/levels differ each run */

    queue_init(&q);

    /* Populate the queue with random users */
    result = queue_enqueue_random_users(&q, numUsers);
    if (result != 0) {
        printf("Error: failed to enqueue random users.\n");
        return 1;
    }

    printf("Successfully enqueued %d users.\n\n", numUsers);

    /* Drain the queue, printing each user as it comes off */
    printf("Dequeuing users:\n");
    while (!queue_is_empty(&q)) {
        if (queue_dequeue(&q, &dequeuedUser) == 0) {
            printf("Username: %-10s | Level: %2d | Faction: %s\n",
                dequeuedUser.username,
                dequeuedUser.level,
                faction_to_string(dequeuedUser.faction));
        }
    }

    return 0;
}