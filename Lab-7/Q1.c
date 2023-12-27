// Aim of the program:  Write a program to find the maximum profit nearest to but not
// exceeding the given knapsack capacity using the Fractional Knapsack algorithm.
// Notes# Declare a structure ITEM having data members item_id, item_profit, item_weight and
// profit_weight_ratio. Apply heap sort technique to sort the items in non-increasing order,
// according to their profit /weight.

// Input:
// Enter the number of items: 3
// Enter the profit and weight of item no 1: 27 16
// Enter the profit and weight of item no 2: 14 12
// Enter the profit and weight of item no 3: 26 13
// Enter the capacity of knapsack:18

// Output:
// Item No profit Weight Amount to be taken
// 3 26.000000 13.000000 1.000000
// 1 27.000000 16.000000 0.312500
// 2 14.000000 12.000000 0.000000
// Maximum profit: 34.437500

#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
    int item_id;
    float item_profit;
    float item_weight;
    float profit_weight_ratio;
} Item;

int compare_items(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;

    if (item1->profit_weight_ratio < item2->profit_weight_ratio) {
        return 1;
    } else if (item1->profit_weight_ratio > item2->profit_weight_ratio) {
        return -1;
    } else {
        return 0;
    }
}

float fractional_knapsack(Item *items, int n, float capacity) {
    float current_weight = 0.0;
    float max_profit = 0.0;
    qsort(items, n, sizeof(Item), compare_items);
    for (int i = 0; i < n; i++) {
        if (current_weight + items[i].item_weight <= capacity) {
            current_weight += items[i].item_weight;
            max_profit += items[i].item_profit;
        } else {
            float fraction = (capacity - current_weight) / items[i].item_weight;
            max_profit += fraction * items[i].item_profit;
            current_weight = capacity;
            break;
        }
    }

    return max_profit;
}

int main() {
    int n;
    float capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item *items = malloc(n * sizeof(Item));

    for (int i = 0; i < n; i++) {
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%f %f", &items[i].item_profit, &items[i].item_weight);
        items[i].item_id = i + 1;
        items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
    }

    printf("Enter the capacity of knapsack: ");
    scanf("%f", &capacity);

    float max_profit = fractional_knapsack(items, n, capacity);

    printf("Item No\tprofit\tWeight\tAmount to be taken\n");

    float current_weight = 0.0;

    for (int i = 0; i < n; i++) {
        printf("%d\t%.6f\t%.6f\t%.6f\n", items[i].item_id, items[i].item_profit, items[i].item_weight, items[i].item_weight <= capacity ? 1.0 : (capacity - (current_weight - items[i].item_weight)) / items[i].item_weight);
    }

    printf("Maximum profit: %.6f\n", max_profit);

    free(items);

    return 0;
}