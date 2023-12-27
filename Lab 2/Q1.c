// Write a program in C to convert the first ‘n’ decimal numbers of a disc file to binary using recursion. Store the binary value in a separate disc file. 

// Note# Read the value of ‘n’, source file name and destination file name from command line arguments. Display the decimal numbers and their equivalent binary numbers from the output file. 

// Give the contents of the input disc file “inDec.dat” as 
// 30  75   2564  …

// Contents of the output disc file “outBin.dat” as 
// The binary equivalent of 30 is 0000000000011110
// The binary equivalent of 75 is 0000000001001011
// The binary equivalent of 2564 is 0000101000000100 

// Terminal Input:
// $gcc lab2q1.c -o lab2q1
// $./lab2q1 150 inDec.dat outBin.dat

// Output: Content of the first ‘n’ decimal and their equivalent binary numbers


#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int decimal, FILE *outFile) {
    if (decimal == 0) {
        return;
    }
    
    decimalToBinary(decimal / 2, outFile);
    fprintf(outFile, "%d", decimal % 2);
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    if (n <= 0) {
        printf("Invalid value of 'n'\n");
        return 1;
    }
    FILE *sourceFile = fopen(argv[2], "r");
    FILE *destFile = fopen(argv[3], "w");
    
    int decimal;
    while (n > 0 && fscanf(sourceFile, "%d", &decimal) == 1) {
        fprintf(destFile, "The binary equivalent of %d is ", decimal);
        decimalToBinary(decimal, destFile);
        fprintf(destFile, "\n");
        n--;
    }
    fclose(sourceFile);
    fclose(destFile);
    destFile = fopen(argv[3], "r");
    char line[100];
    while (fgets(line, sizeof(line), destFile) != NULL) {
        printf("%s", line);
    }
    fclose(destFile);
    return 0;
}
