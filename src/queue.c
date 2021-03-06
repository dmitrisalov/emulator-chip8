#include <stdlib.h>

#include "queue.h"

Queue* queue_new() {
    Queue* queue = malloc(sizeof(Queue));
    queue->head = NULL;

    return queue;
}

void queue_push(Queue* queue, uint16_t value) {
    if (queue == NULL) {
        return;
    }

    // Create node that points to existing head.
    Node* node = malloc(sizeof(Node));
    node->value = value;
    node->next = queue->head;

    // Set the head to the new node.
    queue->head = node;
}

uint16_t queue_pop(Queue* queue) {
    if (queue == NULL || queue->head == NULL) {
        return 0;
    }

    Node* prev_node = NULL;
    Node* current_node = queue->head;

    while (current_node->next != NULL) {
        prev_node = current_node;
        current_node = current_node->next;
    }

    if (prev_node) {
        prev_node->next = NULL;
    }
    else {
        queue->head = NULL;
    }

    uint16_t retval = current_node->value;
    free(current_node);

    return retval;
}

int queue_empty(Queue* queue) {
    if (queue == NULL) {
        return 1;
    }

    return queue->head == NULL;
}

void queue_delete(Queue** queue) {
    while ((*queue)->head != NULL) {
        queue_pop(*queue);
    }

    free(*queue);
    *queue = NULL;
}