#include <stdio.h>
#include <stdlib.h>
#define MAXN 50

struct test {
    int x, y;
};

/*  Sorting by y. */
int comp(const void *a, const void *b) {
    struct test *i = (struct test *) a;
    struct test *j = (struct test *) b;

    if(i->y > j->y) return 1;
    if( i->y < j->y ) return -1;
    return 0;
}

int main() {
    struct test z[MAXN];
    int n;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d %d", &z[i].x, &z[i].y);

    qsort(z, n, sizeof(struct test), comp);

    for(int i = 0; i < n; i++) printf("[%d: %d] ", z[i].x, z[i].y);
    printf("\n");

    return 0;
}
