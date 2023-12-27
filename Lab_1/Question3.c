// 1.3 Aim of the program: Write a program to read ‘n’ integers from a disc file that must contain some duplicate values and store them into an array. 
// Perform the following operations on the array.
// a) Find out the total number of duplicate elements.
// b) Find out the most repeating element in the array.

// Input:
// Enter how many numbers you want to read from file: 15

// Output:
// The content of the array: 10 40 35 47 68 22 40 10 98 10 50 35 68 40 10
// Total number of duplicate values = 4
// The most repeating element in the array = 10


#include<stdio.h>

int mostRepeating(int a[],int n){
    int maxC=0;
    int maxElement=0;
    for(int i=0;i<n;i++){
        int c=0;
        for(int j=0;j<n;j++){
            if(a[i]==a[j]){
                c++;
            }
        }
        if(c>maxC){
            maxC=c;
            maxElement=a[i];
        }
    }
    return maxElement;
}
int removeAllInstances(int a[],int n,int val){
    int c1=0;
    for(int i=0;i<n;i++){
        if(a[i+c1]==val){
            c1++;
        }
        a[i]=a[i+c1];
    }
    return (n-c1);
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
    int mr=mostRepeating(arr,n);
    printf("The most repeating element is %d.",mr);
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
                n=removeAllInstances(arr,n,arr[i]);
                break;
            }
        }
    }
    printf("\nThe total number of all duplicates is %d",count);
    
    return 0;
}
