#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int merge(int arr[], int low, int mid, int high) {
    int i, j, k;
    int comparisons = 0;

    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = low;

    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    return comparisons;
}

int mergeSort(int arr[], int left, int right) {
    int c = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        c =c + mergeSort(arr, left, mid);
        c =c + mergeSort(arr, mid + 1, right);
        c =c + merge(arr, left, mid, right);
    }
    return c;
}

void saveToFile(const char *fileName, int arr[], int n) {
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error opening the file for writing.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);
}

int main() {
    int choice;
    int comparisons;

    do {
        printf("\nMAIN MENU (MERGE SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 3) {
            int n = 10;  // Number of elements in each input file
            int arr[n];
            char inFileName[20], outFileName[20];

            switch (choice) {
                case 1:
                    strcpy(inFileName, "inAsce.dat");
                    strcpy(outFileName, "outMergeAsce.dat");
                    break;
                case 2:
                    strcpy(inFileName, "inDesc.dat");
                    strcpy(outFileName, "outMergeDesc.dat");
                    break;
                case 3:
                    strcpy(inFileName, "inRand.dat");
                    strcpy(outFileName, "outMergeRand.dat");
                    break;
            }

            FILE *inputFile = fopen(inFileName, "r");
            if (inputFile == NULL) {
                printf("Error opening the input file.\n");
                return 1;
            }

            for (int i = 0; i < n; i++) {
                fscanf(inputFile, "%d", &arr[i]);
            }

            printf("\nBefore Sorting: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }

            fclose(inputFile);

            comparisons = mergeSort(arr, 0, n - 1);

            saveToFile(outFileName, arr, n);

            

            printf("\nAfter Sorting: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }

            printf("\nNumber of Comparisons: %d\n", comparisons);
        }
    } while (choice != 4);

    return 0;
}
