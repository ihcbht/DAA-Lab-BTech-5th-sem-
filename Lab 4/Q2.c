#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int partition(int arr[], int low, int high, int *c) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        (*c)++;
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

void quickSort(int arr[], int low, int high, int *comparisons) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons);
        quickSort(arr, low, pi - 1, comparisons);
        quickSort(arr, pi + 1, high, comparisons);
    }
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
        printf("\nMAIN MENU (QUICK SORT)\n");
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
                    strcpy(outFileName, "outQuickAsce.dat");
                    break;
                case 2:
                    strcpy(inFileName, "inDesc.dat");
                    strcpy(outFileName, "outQuickDesc.dat");
                    break;
                case 3:
                    strcpy(inFileName, "inRand.dat");
                    strcpy(outFileName, "outQuickRand.dat");
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

            fclose(inputFile);
            printf("\nBefore Sorting: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }

            comparisons = 0;
            quickSort(arr, 0, n - 1, &comparisons);

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
