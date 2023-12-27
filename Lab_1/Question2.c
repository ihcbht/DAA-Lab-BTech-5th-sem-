// 1.2 Aim of the program: Given an array arr[] of size N, find the prefix sum of the array. A prefix sum array is another array prefixSum[]
// of the same size, such that the value of prefixSum[i] is arr[0] + arr[1] + arr[2] . . . arr[i].

// Input Array: 	3 	4 	5 	1	 2
// Output Array: 	3 	7 	12 	13 	15


#include<stdio.h>

int prefixSum(int a[],int i){
    int sum=0;
    sum=a[i]+a[i-1];
    return sum;
}
int main(){
    printf("Enter the number of elements you want to be in your array:");
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter the %d element:",(i+1));
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<n;i++){
        arr[i]=prefixSum(arr,i);
    }
    printf("The Prefix Sum array is:\n");
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    
    return 0;
}