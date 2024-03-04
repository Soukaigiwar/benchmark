/*
 * Nome do Arquivo: benchmark.c
 * Autor: SoukaigWar (Sergio Mello)
 * Data: 04/03/2024
 * Descrição: Testa o tempo de execução do algorítmo no arquivo teste.c
*/

/*
 * This file is an example of code to get benchmark points.
 * Replace all contents to get your own program points.
*/

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* arr, int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int* arr, int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void teste() {
    /*
     * This block is an example of code to get benchmark points.
     * Replace all contents to get your own program points.
    */
    
    int n = 1000;
    int* arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    selectionSort(arr, n);

    free(arr);
}
