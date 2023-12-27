#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n, int *comparisons) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            (*comparisons)++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void readDataFromFile(const char *filename, int arr[], int n) {
    FILE *file = fopen(filename, "r");
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);
}

void writeDataToFile(const char *filename, int arr[], int n) {
    FILE *file = fopen(filename, "w");
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d ", arr[i]);
    }
    fclose(file);
}

int main() {
    int option;
    while (1) {
        printf("MAIN MENU (INSERTION SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. EXIT\n");

        scanf("%d", &option);
        if (option == 4) {
            break;
        }

        const char *inputFilename = "";
        const char *outputFilename = "";

        if (option == 1) {
            inputFilename = "inAsce.dat";
            outputFilename = "outInsAsce.dat";
        } else if (option == 2) {
            inputFilename = "inDesc.dat";
            outputFilename = "outInsDesc.dat";
        } else if (option == 3) {
            inputFilename = "inRand.dat";
            outputFilename = "outInsRand.dat";
        } else {
            printf("Invalid option\n");
            continue;
        }

        const int n = 10;  // Number of elements in each input file
        int input_data[n];
        int comparisons = 0;

        readDataFromFile(inputFilename, input_data, n);
        printf("Before Sorting: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", input_data[i]);
        }
        printf("\n");

        insertionSort(input_data, n, &comparisons);

        writeDataToFile(outputFilename, input_data, n);
        printf("After Sorting: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", input_data[i]);
        }
        printf("\n");
        printf("Number of Comparisons: %d\n", comparisons);

        if (comparisons == 0) {
            printf("Scenario: Best-case\n");
        } else if (comparisons >= (n * (n - 1)) / 2) {
            printf("Scenario: Worst-case\n");
        } else {
            printf("Scenario: Average-case\n");
        }
    }

    return 0;
}
