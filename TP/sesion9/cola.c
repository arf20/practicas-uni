#include <stdlib.h>

#include "cola.h"

typedef struct node_s {
	data_t data;
	struct node_s *next;
} node_t;

typedef struct queue_s {
	node_t *front, *back;	
} queue_t;

queue_t *
queue_create() {
	queue_t *q = malloc(sizeof(queue_t));
	node_t *n = malloc(sizeof(node_t));
	q->front = n;
	q->back = n;
	return q;
}

queue_t *
queue_insert(queue_t *q, data_t d) {
	q->back->next = malloc(sizeof(node_t));
	q->back->next->data = d;
	q->back->next->next = NULL;
	q->back = q->back->next;
	return q;
}

int
queue_empty(queue_t *c) {
	return c->front == c->back;
}

data_t
queue_pop(queue_t *c) {
	data_t d = c->front->next->data;
	node_t *n = c->front;
	c->front = n->next;
	free(n);
	return d;
}

void
queue_free(queue_t *c) {
	node_t *next;
	for (node_t *n = c->front; n != NULL;) {
		next = n->next;
		free(n);
		n = next;	
	}
	free(c);
}



