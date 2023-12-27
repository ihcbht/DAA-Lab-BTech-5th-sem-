// Aim of the program: Write a program to implement the matrix chain multiplication problem
//  using M-table & S-table to find optimal parenthesization of a matrix-chain product.
//   Print the number of scalar multiplications required for the given input.
// Note# Dimensions of the matrices can be inputted as row and column values. 
//Validate the dimension compatibility.
// Input: 
// Enter number of matrices: 4
// Enter row and col size of A1: 30  35
// Enter row and col size of A2: 35  15
// Enter row and col size of A3: 15  5
// Enter row and col size of A4: 5  10
// Output:
// M Table:
// 0    	15750  7875  	9375
// 0    	0      	2625  	4375
// 0    	0      	0      	750
// 0    	0      	0      	0
// S Table:
// 0    	1      	1      	3
// 0    	0      	2      	3
// 0	    0      	0      	3
// 0    	0      	0      	0
// Optimal parenthesization: ( ( A1   (A2   A3))   A4)
// The optimal ordering of the given matrices requires 9375 scalar multiplications.


#include <stdio.h>

void matrixChainOrder(int dims[], int n, int M[5][5], int S[5][5]) {
    for (int i = 1; i <= n; i++) {
        M[i][i] = 0;
    }

    for (int chainLen = 2; chainLen <= n; chainLen++) {
        for (int i = 1; i <= n - chainLen + 1; i++) {
            int j = i + chainLen - 1;
            M[i][j] = 999999;  // Initialize to a large value

            for (int k = i; k < j; k++) {
                int cost = M[i][k] + M[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (cost < M[i][j]) {
                    M[i][j] = cost;
                    S[i][j] = k;
                }
            }
        }
    }
}

void printOptimalParenthesization(int S[5][5], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParenthesization(S, i, S[i][j]);
        printf(" ");
        printOptimalParenthesization(S, S[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int n;
    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int dims[6];  // Array to store dimensions of matrices

    for (int i = 0; i < n; i++) {
        printf("Enter row and col size of A%d: ", i + 1);
        scanf("%d %d", &dims[i], &dims[i + 1]);
    }

    int M[5][5] = {0};  // M-table
    int S[5][5] = {0};  // S-table

    matrixChainOrder(dims, n, M, S);

    printf("M Table:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j >= i) {
                printf("%d ", M[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }

    printf("\nS Table:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j > i) {
                printf("%d ", S[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }

    printf("\nOptimal parenthesization: ");
    printOptimalParenthesization(S, 1, n);
    printf("\n");

    printf("The optimal ordering of the given matrices requires %d scalar multiplications.\n", M[1][n]);

    return 0;
}