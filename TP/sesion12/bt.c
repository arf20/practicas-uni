#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "bt.h"

struct bt_s {
	int e;
	struct bt_s *l, *r;
};

bt_t
bt_create() {
	return NULL;
}

void
bt_free(bt_t t) {
	if (t == NULL) return;
	bt_free(t->l);
	bt_free(t->r);
	free(t);
}

int
bt_exists(bt_t t, int e) {
	if (t == NULL) return 0;
	if (e == t->e) return 1;
	if (e < t->e) return bt_exists(t->l, e);
	else return bt_exists(t->r, e);
}

void
bt_insert(bt_t *t, int e) {
	if (*t == NULL) {
		*t = malloc(sizeof(bt_t));
		(*t)->e = e;
		(*t)->l = (*t)->r = NULL;
		return;
	}
	
	if (e < (*t)->e)
		bt_insert(&(*t)->l, e);
	else if (e > (*t)->e)
		bt_insert(&(*t)->r, e);
}

void
bt_delete(bt_t *t, int e) {
	if (*t == NULL) return;
	if (e < (*t)->e) bt_delete(&(*t)->l, e);
	else if (e > (*t)->e) bt_delete(&(*t)->r, e);
	else if ((*t)->l == NULL && (*t)->r == NULL) {
		free(*t);
		*t = NULL;
	}
	else if ((*t)->l == NULL) {
		bt_t l = (*t)->l;
		free(*t);
		*t = l;
	}
	else if ((*t)->r == NULL) {
		bt_t r = (*t)->r;
		free(*t);
		*t = r;
	}
	else ;	
}

char *
bt_tostring(char *s, bt_t t) {
	static char buff[256];
	if (t) {
		bt_tostring(s, t->l);
		snprintf(buff, 256, " %d", t->e);
		strcat(s, buff);
		bt_tostring(s, t->r);
	}
	
	return s;

}

void
bt_insert_all(bt_t a, bt_t *t) {
	if (a == NULL) return;
	bt_insert(t, a->e);
	bt_insert_all(a->l, t);
	bt_insert_all(a->r, t);
}

bt_t
bt_union(bt_t a, bt_t b) {
	bt_t c = bt_create();

	bt_insert_all(a, &c);
	bt_insert_all(b, &c);

	return c;
}

bt_t
bt_intersect(bt_t a, bt_t b) {
	bt_t c = bt_create();
	
}