// 2Aim of the program: Huffman coding assigns variable length codewords to fixed length input characters
 //based on their frequencies or probabilities of occurrence. Given a set of characters along with their 
 //frequency of occurrences, write a c program to construct a Huffman tree.
// Note# 
// •	Declare a structure SYMBOL having members alphabet and frequency. Create a Min-Priority Queue, keyed on frequency attributes. 
// •	Create an array of structures where size=number of alphabets.
// Input:      
// Enter the number of distinct alphabets: 6
// Enter the alphabets:     	a      	b      	c      	d      	e      	f
// Enter its frequencies:   	45    	13    	12    	16    	9      	5
// Output:
// In-order traversal of the tree (Huffman): a  c  b  f  e  d


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char alphabet;
    int frequency;
    struct Node *left, *right;
} Node;

typedef struct MinHeap {
    Node **arr;
    int size;
} MinHeap;

Node *newNoded(char alphabet, int frequency) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->alphabet = alphabet;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}

MinHeap *createMinHeap(int capacity) {
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->arr = (Node **)malloc(capacity * sizeof(Node *));
    minHeap->size = 0;
    return minHeap;
}

void swapMinHeapNodes(Node **a, Node **b) {
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap *minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->arr[left]->frequency < minHeap->arr[smallest]->frequency) {
        smallest = left;
    }

    if (right < minHeap->size && minHeap->arr[right]->frequency < minHeap->arr[smallest]->frequency) {
        smallest = right;
    }

    if (smallest != idx) {
        swapMinHeapNodes(&minHeap->arr[smallest], &minHeap->arr[idx]);
        minHeapify(minHeap, smallest);
    }
}

Node *extractMin(MinHeap *minHeap) {
    if (minHeap->size == 0) {
        return NULL;
    }

    Node *minNode = minHeap->arr[0];
    minHeap->arr[0] = minHeap->arr[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return minNode;
}

void insertMinHeap(MinHeap *minHeap, Node *node) {
    minHeap->size++;
    int i = minHeap->size - 1;
    while (i && node->frequency < minHeap->arr[(i - 1) / 2]->frequency) {
        minHeap->arr[i] = minHeap->arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->arr[i] = node;
}

void buildMinHeap(MinHeap *minHeap, Node *arr[], int n) {
    for (int i = 0; i < n; i++) {
        minHeap->arr[i] = arr[i];
    }
    minHeap->size = n;

    for (int i = (n - 1) / 2; i >= 0; i--) {
        minHeapify(minHeap, i);
    }
}

Node *buildHuffmanTree(Node *arr[], int n) {
    MinHeap *minHeap = createMinHeap(n);
    buildMinHeap(minHeap, arr, n);

    while (minHeap->size > 1) {
        Node *left = extractMin(minHeap);
        Node *right = extractMin(minHeap);

        Node *newNode = newNoded('$', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        insertMinHeap(minHeap, newNode);
    }

    return extractMin(minHeap);
}

void inorderTraversal(Node *root) {
    if (root) {
        inorderTraversal(root->left);
        printf("%c ", root->alphabet);
        inorderTraversal(root->right);
    }
}

int main() {
    int n;
    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);

    Node *arr[n];

    printf("Enter the alphabets: ");
    for (int i = 0; i < n; i++) {
        char alphabet;
        scanf(" %c", &alphabet);
        arr[i] = newNoded(alphabet, 0);
    }

    printf("Enter the frequencies: ");
    for (int i = 0; i < n; i++) {
        int frequency;
        scanf("%d", &frequency);
        arr[i]->frequency = frequency;
    }

    Node *root = buildHuffmanTree(arr, n);
    printf("In-order traversal of the tree (Huffman): ");
    inorderTraversal(root);

    return 0;
}
