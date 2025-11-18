#include <limits.h>
#include "sequential_merge.h"

void sequentialMerge(int *A, int sizeA, int *B, int sizeB, int *C) {

    int i = 0;   // índice de A
    int j = 0;   // índice de B
    int k = 0;   // índice de C

    while (k < sizeA + sizeB) {

        // si me paso del arreglo ? usar +8
        int ai = (i < sizeA) ? A[i] : INT_MAX;
        int bj = (j < sizeB) ? B[j] : INT_MAX;

        if (ai < bj) {
            C[k] = ai;
            i++;
        } else {
            C[k] = bj;
            j++;
        }

        k++;
    }
}


