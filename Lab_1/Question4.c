// 1.4 Aim of the program: Write a function to ROTATE_RIGHT(p1, p2 ) right an array for first p2 elements by 1 position using EXCHANGE(p, q) function 
// that swaps/exchanges the numbers p & q. Parameter p1 be the starting address of the array and p2 be the number of elements to be rotated.  

// Input:
// Enter an array A of size N (9): 11 22 33 44 55 66 77 88 99 
// Call the function ROTATE_RIGHT(A, 5)
// Output:
// Before ROTATE: 	11 22 33 44 55 66 77 88 99 
// After   ROTATE: 	55 11 22 33 44 66 77 88 99


#include<stdio.h>

void Rotate_Right(int arr[],int a,int n){
    int temp=arr[a-1];
    for(int i=a-1;i>=1;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=temp;
    printf("The array after the rotation is:");
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
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
    int ele;
    printf("Enter the position of the element to be rotated:");
    scanf("%d",&ele);
    Rotate_Right(arr,ele,n);
    return 0;
}