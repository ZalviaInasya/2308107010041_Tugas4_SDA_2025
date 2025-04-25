#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sorting.h"

#define MAX_ALGO 6
#define MAX_WORD_LENGTH 100

typedef struct {
    char *name;
    void (*sortInt)(int[], int);
    void (*sortStr)(char*[], int);
} SortAlgorithm;

int getJumlahDataDariInput() {
    int n;
    printf("Masukkan jumlah data yang ingin diuji: ");
    scanf("%d", &n);
    return n;
}

void loadNumbers(const char *filename, int *arr, int n) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Gagal membuka file data_angka.txt");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);
}

void loadWords(const char *filename, char **arr, int n) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Gagal membuka file data_kata.txt");
        exit(1);
    }
    char buffer[MAX_WORD_LENGTH];
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%s", buffer);
        arr[i] = strdup(buffer);
    }
    fclose(fp);
}

void copyArrayInt(int *dst, int *src, int n) {
    for (int i = 0; i < n; i++) {
        dst[i] = src[i];
    }
}

void copyArrayStr(char **dst, char **src, int n) {
    for (int i = 0; i < n; i++) {
        dst[i] = strdup(src[i]);
    }
}

void freeArrayStr(char **arr, int n) {
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
}

void testInt(int *original, int n, SortAlgorithm algos[]) {
    printf("+----------------------+----------------+---------------------+\n");
    printf("|                     PENGUJIAN DATA ANGKA                    |\n");
    printf("+----------------------+----------------+---------------------+\n");
    printf("|    Nama Algoritma    | Waktu (second) |   Memori Digunakan  |\n");
    printf("+----------------------+----------------+---------------------+\n");

    for (int i = 0; i < MAX_ALGO; i++) {
        int *arr = malloc(n * sizeof(int));
        copyArrayInt(arr, original, n);

        clock_t start = clock();
        if (algos[i].sortInt) {
            algos[i].sortInt(arr, n);
        }
        double time_spent = (double)(clock() - start) / CLOCKS_PER_SEC;
        double mem_used_kb = (n * sizeof(int)) / 1024.0;

        printf("| %-20s | %14.4f | %9.2f KB        |\n", algos[i].name, time_spent, mem_used_kb);
        free(arr);
    }

    printf("+----------------------+----------------+---------------------+\n\n");
}

void testStr(char **original, int n, SortAlgorithm algos[]) {
    printf("+----------------------+----------------+---------------------+\n");
    printf("|                     PENGUJIAN DATA KATA                     |\n");
    printf("+----------------------+----------------+---------------------+\n");
    printf("|    Nama Algoritma    | Waktu (second) |   Memori Digunakan  |\n");
    printf("+----------------------+----------------+---------------------+\n");

    for (int i = 0; i < MAX_ALGO; i++) {
        char **arr = malloc(n * sizeof(char *));
        copyArrayStr(arr, original, n);

        clock_t start = clock();
        if (algos[i].sortStr) {
            algos[i].sortStr(arr, n);
        }
        double time_spent = (double)(clock() - start) / CLOCKS_PER_SEC;

        // Estimasi: pointer array + asumsi rata-rata panjang kata (misalnya 20 char)
        double mem_used_kb = (n * sizeof(char *) + n * 20 * sizeof(char)) / 1024.0;

        printf("| %-20s | %14.4f | %9.2f KB        |\n", algos[i].name, time_spent, mem_used_kb);
        freeArrayStr(arr, n);
    }

    printf("+----------------------+----------------+---------------------+\n\n");
}

int main() {
    int n = getJumlahDataDariInput();
    int *dataInt = malloc(n * sizeof(int));
    char **dataStr = malloc(n * sizeof(char*));

    loadNumbers("data_angka.txt", dataInt, n);
    loadWords("data_kata.txt", dataStr, n);

    SortAlgorithm algos[MAX_ALGO] = {
        {"Bubble Sort", bubbleSortInt, bubbleSortStr},
        {"Selection Sort", selectionSortInt, selectionSortStr},
        {"Insertion Sort", insertionSortInt, insertionSortStr},
        {"Merge Sort", mergeSortIntWrapper, mergeSortStrWrapper},
        {"Quick Sort", quickSortIntWrapper, quickSortStrWrapper},
        {"Shell Sort", shellSortInt, shellSortStr}
    };

    testInt(dataInt, n, algos);
    testStr(dataStr, n, algos);

    free(dataInt);
    freeArrayStr(dataStr, n);

    return 0;
}
