#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 50

/*  Complexity: O(Nlog(n))
    qsort(void *v, int n, size_t s, int compare(const void *, const void *))
    n = number of items
    s = number of bytes needed
    compare = function that will compare items
    In relation to compare function:
    a == b --> 0
    a > b  --> -1 (for ascending order)
    a < b  --> 1 (for descending order) */

int compare_asc(const void *a, const void *b) {
    if(*(float *) a == *(float *) b) return 0;
    else if(*(float *) a > *(float *) b) return 1;
    else return -1;
}

int compare_desc(const void *a, const void *b) {
    if(*(float *) a == *(float *) b) return 0;
    else if(*(float *) a > *(float *) b) return -1;
    else return 1;
}

/* Function for char array */
int comp(const void *a, const void *b) {
  return strcmp(*(const char **)a, *(const char **)b);
}

void printResult(int v[], int n) {
    for(int i = 0; i < n; i++) printf("%d ", v[i]);
}

int main() {
    int v[MAXN], n;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);

    qsort(v, n, sizeof(int), compare_asc);
    // qsort(v, n, sizeof(char *), comp);
    printResult(v, n);
    return 0;
}
