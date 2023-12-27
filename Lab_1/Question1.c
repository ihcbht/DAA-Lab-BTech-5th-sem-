// 1.1 Aim of the program: Write a program to find out the second smallest and second largest element stored in an array of n integers. 
// Input: Size of the array is ‘n’ and read ‘n’ number of elements from a disc file.
// Output: Second smallest, Second largest


#include<stdio.h>

int main(){
    printf("Enter the number of elements you want to be in your array:");
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter the %d element:",(i+1));
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    int second_smallest=arr[1];
    int second_largest=arr[n-2];
    printf("\nThe Second Smallest Element in the array is %d.",second_smallest);
    printf("\nThe Second Largest Element in the array is %d.",second_largest);
    return 0;
}