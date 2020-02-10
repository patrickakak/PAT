#include <stdlib.h>
int compare(const void *a, const void *b) {
    ElementType r = *(ElementType*)a - *(ElementType*)b;
    if (r < 0) return -1;
    else if (r > 0) return 1;
    else return 0;
}
ElementType Median(ElementType A[], int N) {
    qsort(A, N, sizeof(ElementType), compare);
    return A[N/2];
}
