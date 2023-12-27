// 7.2 Aim of the program: Write a program to find out the Longest Common 
//Subsequence of two given strings. Calculate length of the LCS.
// Input:
// Enter the first string into an array: 10010101
// Enter the second string into an array: 010110110
// Output:
//        LCS: 100110
//        LCS Length: 6


#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void findLCS(char *str1, char *str2, int m, int n) {
    int LCS[m + 1][n + 1];

    // Calculate LCS table using dynamic programming
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                LCS[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
        }
    }

    // LCS length is stored in LCS[m][n]
    int lcs_length = LCS[m][n];

    // Backtrack to find the LCS
    char lcs_string[lcs_length + 1];
    lcs_string[lcs_length] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs_string[--lcs_length] = str1[i - 1];
            i--;
            j--;
        } else if (LCS[i - 1][j] > LCS[i][j - 1])
            i--;
        else
            j--;
    }

    printf("LCS: %s\n", lcs_string);
    printf("LCS Length: %d\n", LCS[m][n]);
}

int main() {
    char str1[100], str2[100];

    printf("Enter the first string into an array: ");
    scanf("%s", str1);
    printf("Enter the second string into an array: ");
    scanf("%s", str2);

    int m = strlen(str1);
    int n = strlen(str2);

    findLCS(str1, str2, m, n);

    return 0;
}