#include <stdio.h>

// Structure for items
struct Item {
    int weight;
    int profit;
    float ratio;
};

// Function to sort items by ratio (descending)
void sort(struct Item items[], int n) {
    int i, j;
    struct Item temp;

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(items[i].ratio < items[j].ratio) {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    float capacity, totalProfit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter weights and profits:\n");
    for(i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].profit);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    // Sort items by ratio
    sort(items, n);

    printf("\nSelected items:\n");

    for(i = 0; i < n; i++) {
        if(capacity >= items[i].weight) {
            // Take full item
            printf("Item %d fully taken\n", i+1);
            capacity -= items[i].weight;
            totalProfit += items[i].profit;
        } else {
            // Take fraction
            float fraction = capacity / items[i].weight;
            printf("Item %d taken %.2f fraction\n", i+1, fraction);
            totalProfit += items[i].profit * fraction;
            break;
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);

    return 0;
}
