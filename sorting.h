#ifndef SORTING_H
#define SORTING_H

#include <string.h>
#include <stdlib.h>

// Bubble Sort
void bubbleSortInt(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
}

void bubbleSortStr(char *arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char *tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
}

// Selection Sort
void selectionSortInt(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        int tmp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = tmp;
    }
}

void selectionSortStr(char *arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (strcmp(arr[j], arr[minIdx]) < 0)
                minIdx = j;
        char *tmp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = tmp;
    }
}

// Insertion Sort
void insertionSortInt(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

void insertionSortStr(char *arr[], int n) {
    for (int i = 1; i < n; i++) {
        char *key = arr[i];
        int j = i - 1;
        while (j >= 0 && strcmp(arr[j], key) > 0)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

// Merge Sort (recursive)
void mergeInt(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    free(L); free(R);
}

void mergeSortInt(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSortInt(arr, l, m);
        mergeSortInt(arr, m + 1, r);
        mergeInt(arr, l, m, r);
    }
}

void mergeStr(char *arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    char **L = malloc(n1 * sizeof(char *));
    char **R = malloc(n2 * sizeof(char *));
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (strcmp(L[i], R[j]) <= 0) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    free(L); free(R);
}

void mergeSortStr(char *arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSortStr(arr, l, m);
        mergeSortStr(arr, m + 1, r);
        mergeStr(arr, l, m, r);
    }
}

// Quick Sort (recursive)
int partitionInt(int arr[], int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++)
        if (arr[j] <= pivot)
            { int tmp = arr[++i]; arr[i] = arr[j]; arr[j] = tmp; }
    int tmp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = tmp;
    return i + 1;
}

void quickSortInt(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionInt(arr, low, high);
        quickSortInt(arr, low, pi - 1);
        quickSortInt(arr, pi + 1, high);
    }
}

int partitionStr(char *arr[], int low, int high) {
    char *pivot = arr[high]; int i = low - 1;
    for (int j = low; j < high; j++)
        if (strcmp(arr[j], pivot) <= 0)
            { char *tmp = arr[++i]; arr[i] = arr[j]; arr[j] = tmp; }
    char *tmp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = tmp;
    return i + 1;
}

void quickSortStr(char *arr[], int low, int high) {
    if (low < high) {
        int pi = partitionStr(arr, low, high);
        quickSortStr(arr, low, pi - 1);
        quickSortStr(arr, pi + 1, high);
    }
}

// Shell Sort
void shellSortInt(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2)
        for (int i = gap; i < n; i++) {
            int temp = arr[i], j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
}

void shellSortStr(char *arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2)
        for (int i = gap; i < n; i++) {
            char *temp = arr[i]; int j;
            for (j = i; j >= gap && strcmp(arr[j - gap], temp) > 0; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
}

// === WRAPPER FUNCTIONS ===

// Untuk menyesuaikan dengan pointer fungsi: void (*sortInt)(int[], int)
void mergeSortIntWrapper(int arr[], int n) {
    mergeSortInt(arr, 0, n - 1);
}

void mergeSortStrWrapper(char *arr[], int n) {
    mergeSortStr(arr, 0, n - 1);
}

void quickSortIntWrapper(int arr[], int n) {
    quickSortInt(arr, 0, n - 1);
}

void quickSortStrWrapper(char *arr[], int n) {
    quickSortStr(arr, 0, n - 1);
}

#endif
