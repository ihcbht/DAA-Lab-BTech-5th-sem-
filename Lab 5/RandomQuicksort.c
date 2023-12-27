#include<stdio.h>
#include<stdlib.h>

int swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int a[],int p,int q){
    int pI=p+rand()%(q-p+1);
    int pivot=a[pI];
    swap(&a[pI],&a[q]);
    int i=p-1;

    for (int j=p;j<q;j++) {
        if (a[j]<=pivot) {
            i++;
            swap(&a[i],&a[j]);
        }
    }

    swap(&a[i+1],&a[q]);
    return i + 1;
}
void QuickSort(int a[],int p, int q){
    int m;
    if(p<q){
        m=partition(a,p,q);
        QuickSort(a,p,m-1);
        QuickSort(a,m+1,q);
    }
}


int main(){
    int n;
    printf("Enter the value of n:");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        printf("Enter a[%d]:",i);
        scanf("%d",&a[i]);
    }

    printf("The array before Randomised Quick Sort.");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    QuickSort(a,0,n-1);
    printf("\nThe array after Randomised Quick Sort.");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    
}
