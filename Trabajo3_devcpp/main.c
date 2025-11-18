#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sequential_merge.h"
#include "binary_search_classic.h"
#include "binary_search.h"

int main() {

    // --------------------------------------------------------------
    // PRUEBA PEQUEÑA 
    // --------------------------------------------------------------

    int A[] = {2, 5, 9};
    int B[] = {1, 3, 8, 20};
    int C[7];

    clock_t inicio, fin;
    double tiempo;

    inicio = clock(); //Inicio de medición del tiempo

    sequentialMerge(A, 3, B, 4, C);

    fin = clock();     // Final de medición del tiempo

    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

    printf("Resultado merge:\n");
    for (int i = 0; i < 7; i++)
        printf("%d ", C[i]);

    printf("\n\nTiempo de ejecución del Merge secuencial (pequeño): %f segundos\n", tiempo);
    printf("\n\n");

    printf("binarySearch_classic(C, 7, 8) = %d\n",
           binarySearch_classic(C, 7, 8));

    int Aprime[] = {5, 13, 20};
    int Bprime[] = {3, 9, 15};

    printf("binarySearch_Aprime_in_Bprime(8) = %d\n",
           binarySearch_Aprime_in_Bprime(Bprime, 3, 8));

    printf("binarySearch_Bprime_in_Aprime(9) = %d\n",
           binarySearch_Bprime_in_Aprime(Aprime, 3, 9));

    printf("binarySearch_greater(Aprime, 3, 13) = %d\n",
           binarySearch_greater(Aprime, 3, 13));

    printf("\n------------------------------------------------------------\n");
    printf(" AHORA PRUEBA DE TIEMPO REAL CON ARREGLOS GIGANTES\n");
    printf("------------------------------------------------------------\n\n");

    // --------------------------------------------------------------
    // PRUEBA GRANDE 
    // --------------------------------------------------------------

    int sizeA = 100000000;   // 5 millones
    int sizeB = 100000000;   // 5 millones

    printf("Creando arreglos de %d y %d elementos...\n", sizeA, sizeB);

    int *A_big = (int*) malloc(sizeA * sizeof(int));
    int *B_big = (int*) malloc(sizeB * sizeof(int));
    int *C_big = (int*) malloc((sizeA + sizeB) * sizeof(int));

    if (A_big == NULL || B_big == NULL || C_big == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    // Llenar A_big y B_big ordenados
    for (int i = 0; i < sizeA; i++)
        A_big[i] = i * 2;        // pares

    for (int i = 0; i < sizeB; i++)
        B_big[i] = i * 2 + 1;    // impares

    printf("Iniciando medición del tiempo REAL...\n");

    inicio = clock();

    sequentialMerge(A_big, sizeA, B_big, sizeB, C_big);

    fin = clock();

	tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

    printf("\nTiempo del Merge con arreglos gigantes (%d + %d = %d elementos):\n",
           sizeA, sizeB, sizeA + sizeB);

    printf("%f segundos\n", tiempo);

    // Mostrar algunos resultados para verificar
    printf("\nC_big[0] = %d\n", C_big[0]);
    printf("C_big[%d] = %d\n", sizeA + sizeB - 1, C_big[sizeA + sizeB - 1]);

    // Liberar memoria
    free(A_big);
    free(B_big);
    free(C_big);

    return 0;
}

