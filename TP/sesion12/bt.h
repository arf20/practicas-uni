#ifndef _ABB_H
#define _ABB_H

typedef struct bt_s* bt_t;

bt_t bt_create();
void bt_free(bt_t t);
int bt_exists(bt_t t, int e);
void bt_insert(bt_t *t, int e);
void bt_delete(bt_t *t, int e);
bt_t bt_union();
bt_t bt_intersect();
bt_t bt_diff();
char *bt_tostring(char *str, bt_t t);

#endif /* _ABB_H */
