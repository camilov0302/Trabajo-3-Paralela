#include "binary_search_classic.h"

int binarySearch_classic(int *S, int n, int x) {

    int left = 0;
    int right = n - 1;
    int result = -1;   // -1 = no encontrado

    while (left <= right) {

        int mid = (left + right) / 2;

        if (S[mid] == x) {
            result = mid;    // posición 0-based
            break;
        }
        else if (x < S[mid]) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return result;  // retorna índice o -1 si no aparece
}

