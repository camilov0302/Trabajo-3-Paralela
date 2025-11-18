#include "binary_search.h"

// Paso 2.1: smallest j such that aprime < Bprime[j]
int binarySearch_Aprime_in_Bprime(int *Bprime, int sizeB, int aprime) {

    int left = 0;
    int right = sizeB - 1;
    int answer = sizeB;  // si no hay mayor, retorna sizeB

    while (left <= right) {
        int mid = (left + right) / 2;

        if (aprime < Bprime[mid]) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return answer;
}

// Paso 2.2: smallest j such that bprime < Aprime[j]
int binarySearch_Bprime_in_Aprime(int *Aprime, int sizeA, int bprime) {

    int left = 0;
    int right = sizeA - 1;
    int answer = sizeA;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (bprime < Aprime[mid]) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return answer;
}

// Paso 3.2: smallest j such that X[j] > pivot
int binarySearch_greater(int *X, int sizeX, int pivot) {

    int left = 0;
    int right = sizeX - 1;
    int answer = sizeX;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (X[mid] > pivot) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return answer;
}



