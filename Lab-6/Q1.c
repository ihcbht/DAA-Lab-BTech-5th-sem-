// 5.1 Aim of the program: 

// Define a struct person as follows: 
// struct person
// {
// 	int id;
// 	char *name;
// 	int age;
// 	int height;
// 	int weight;
// }; 
// Write a menu driven program to read the data of ‘n’ students from a file and store them in a dynamically allocated array of struct person. 
//Implement the min-heap or max-heap and its operations based on the menu options. 

// Sample Input/Output:
// MAIN MENU (HEAP)
// 1. Read Data
// 2. Create a Min-heap based on the age
// 3. Create a Max-heap based on the weight
// 4. Display weight of the youngest person
// 5. Insert a new person into the Min-heap
// 6. Delete the oldest person
// 7. Exit

// Enter option: 1 
// Id	Name			Age	Height	Weight(pound)
// 0	Adarsh Hota	    39	77		231
// 1	Levi Maier		56	77		129
// 2	Priya Kumari	63	78		240
// 3	Dorothy Helton	47	72		229
// 4	Florence Smith	24	75		171
// 5	Erica Anyan	    38	73		102
// 6	Norma Webster	23	75		145

// Enter option: 4
// Weight of youngest student: 65.77 kg

// Note#: Other menu choices are similarly verified.

#include<stdio.h>
#include<stdlib.h>


struct person{
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

void swap(struct person *a,struct person *b){
    struct person temp=*a;
    *a=*b;
    *b=temp;
}

void min_Heapify_by_age(struct person arr[],int n,int i){
    int smallest=i;
    int lc=(2*i)+1;
    int rc=(2*i)+2;
    if(lc<n && arr[lc].age<arr[smallest].age){
        smallest=lc;
    }
    if(rc<n && arr[rc].age<arr[smallest].age){
        smallest=rc;
    }
    if(smallest!=i){
        swap(&arr[i],&arr[smallest]);
        min_Heapify_by_age(arr,n,smallest);
    }
}

void max_Heapify_by_age(struct person arr[],int n,int i){
    int max=i;
    int lc=(2*i)+1;
    int rc=(2*i)+2;
    if(lc<n && arr[lc].age>arr[max].age){
        max=lc;
    }
    if(rc<n && arr[rc].age>arr[max].age){
        max=rc;
    }
    if(max!=i){
        swap(&arr[i],&arr[max]);
        max_Heapify_by_age(arr,n,max);
    }
}

void max_Heapify_by_weight(struct person arr[],int n,int i){
    int largest=i;
    int lc=(2*i)+1;
    int rc=(2*i)+2;
    if(lc<n && arr[lc].weight>arr[largest].weight){
        largest=lc;
    }
    if(rc<n && arr[rc].weight>arr[largest].weight){
        largest=rc;
    }
    if(largest!=i){
        swap(&arr[i],&arr[largest]);
        min_Heapify_by_age(arr,n,largest);
    }
}

void build_min_Heap_by_Age(struct person arr[],int n){
    for(int i=n/2;i>=0;i--){
        min_Heapify_by_age(arr,n,i);
    }
}

void build_max_Heap_by_Age(struct person arr[],int n){
    for(int i=n/2;i>=0;i--){
        max_Heapify_by_age(arr,n,i);
    }
}

void build_max_Heap_by_Weight(struct person arr[],int n){
    for(int i=n/2;i>=0;i--){
        max_Heapify_by_weight(arr,n,i);
    }
}

void weight_of_youngest_person(struct person arr[],int n){
    int smallest=arr[0].age;
    int w;
    for(int i=1;i<n;i++){
        if(arr[i].age<smallest){
            smallest=arr[i].age;
            w=i;
        }
    }
    printf("\nThe Weight of the Youngest Person is:%d.\n",arr[w].weight);
}

void delete_oldest_person(struct person arr[],int size){
    size--;
    printf("\nId\tName\t\tAge\tHeight\tWeight");
    for(int i=0;i<size;i++){
        printf("\n%d\t%s\t%d\t%d\t%d",arr[i].id,arr[i].name,arr[i].age,arr[i].height,arr[i].weight);
    }
}

int main(){
    printf("MAIN MENU (HEAP)");
    printf("\n1. Read Data");
    printf("\n2. Create a Min-heap based on the age");
    printf("\n3. Create a Max-heap based on the weight");
    printf("\n4. Display weight of the youngest person");
    printf("\n5. Insert a new person into the Min-heap");
    printf("\n6. Delete the oldest person");
    printf("\n7. Exit");
    int ch;

    struct person arr[8];
    arr[0].id=0;
    arr[0].name="Adarsh Hota";
    arr[0].age=39;
    arr[0].height=77;
    arr[0].weight=231;

    arr[1].id=1;
    arr[1].name="Levi Maier";
    arr[1].age=56;
    arr[1].height=77;
    arr[1].weight=129;

    arr[2].id=2;
    arr[2].name="Priya Kumari";
    arr[2].age=63;
    arr[2].height=78;
    arr[2].weight=240;

    arr[3].id=3;
    arr[3].name="Dorothy helton";
    arr[3].age=47;
    arr[3].height=72;
    arr[3].weight=229;

    arr[4].id=4;
    arr[4].name="Florence Smith";
    arr[4].age=24;
    arr[4].height=75;
    arr[4].weight=171;

    arr[5].id=5;
    arr[5].name="Erica Anyan";
    arr[5].age=38;
    arr[5].height=73;
    arr[5].weight=102;

    arr[6].id=6;
    arr[6].name="Norma Webster";
    arr[6].age=23;
    arr[6].height=75;
    arr[6].weight=145;

    do{
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        if(ch==1){
            printf("\nId\tName\t\tAge\tHeight\tWeight");
            for(int i=0;i<7;i++){
                printf("\n%d\t%s\t%d\t%d\t%d",arr[i].id,arr[i].name,arr[i].age,arr[i].height,arr[i].weight);
            }
        }
        else if(ch==2){
            build_min_Heap_by_Age(arr,7);
            printf("\nId\tName\t\tAge\tHeight\tWeight");
            for(int i=0;i<7;i++){
                printf("\n%d\t%s\t%d\t%d\t%d",arr[i].id,arr[i].name,arr[i].age,arr[i].height,arr[i].weight);
            }
        }
        else if(ch==3){
            build_max_Heap_by_Weight(arr,7);
            printf("\nId\tName\t\tAge\tHeight\tWeight");
            for(int i=0;i<7;i++){
                printf("\n%d\t%s\t%d\t%d\t%d",arr[i].id,arr[i].name,arr[i].age,arr[i].height,arr[i].weight);
            }
        }
        else if(ch==4){
            weight_of_youngest_person(arr,7);
        }
        else if(ch==5){
            arr[7].id=7;
            arr[7].name="Ashutosh Das";
            arr[7].age=21;
            arr[7].height=72;
            arr[7].weight=190;
            build_min_Heap_by_Age(arr,8);
            printf("\nId\tName\t\tAge\tHeight\tWeight");
            for(int i=0;i<8;i++){
                printf("\n%d\t%s\t%d\t%d\t%d",arr[i].id,arr[i].name,arr[i].age,arr[i].height,arr[i].weight);
            }
        }
        else if(ch==6){
            build_max_Heap_by_Age(arr,8);
            swap(&arr[0],&arr[7]);
            delete_oldest_person(arr,8);
        }
    }while(ch!=7);
}
