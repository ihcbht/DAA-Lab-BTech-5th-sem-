#include <stdio.h>
int c=0;
int binary_search(int arr[], int n, int srh) {
    int pos = -1;

    for (int start = 0, end = n - 1; start <= end;) {
        c++;
        int mid = start + (end - start) / 2;
        
        if (arr[mid] == srh) {
            pos = mid;
            end = mid - 1;
        } else if (arr[mid] < srh) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    
    return pos;
}

int main() {
    int n, srh;

    printf("Enter array size and search element: ");
    scanf("%d %d", &n, &srh);

    int arr[n];
    printf("Enter sorted array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int pos = binary_search(arr, n, srh);

    if (pos != -1) {
        printf("Element %d found at position %d\n", srh, pos);
    } else {
        printf("Element %d not found\n", srh);
    }
    printf("Number of comparisions:%d",c);
    
    return 0;
}