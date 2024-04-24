#include <stdio.h>

#include "bt.h"

int main() {
	bt_t t1 = bt_create();
    bt_t t2 = bt_create();

    int in;
    while (1) {
        printf("num> ");
        scanf("%d", &in);
        if (in == 0) break;
        bt_insert(&t1, in);
    }

    char buff[256];
    printf("t1: %s\n", bt_tostring(buff, t1));

    while (1) {
        printf("num> ");
        scanf("%d", &in);
        if (in == 0) break;
        bt_insert(&t2, in);
    }

    buff[0] = '\0';
    printf("t2: %s\n", bt_tostring(buff, t2));

    bt_t t3 = bt_union(t1, t2);

    buff[0] = '\0';
    printf("t3: %s\n", bt_tostring(buff, t3));
}

