#include <stdio.h>

int main() {
    int n, c, i, j;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int w[n], bin[n];  // weights and remaining capacity

    printf("Enter item weights:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    printf("Enter bin capacity: ");
    scanf("%d", &c);

    // Initially no bins are used
    int bins_used = 0;

    for(i = 0; i < n; i++) {
        int placed = 0;

        // Try to place item in existing bins
        for(j = 0; j < bins_used; j++) {
            if(bin[j] >= w[i]) {
                printf("Item %d (%d) placed in Bin %d\n", i+1, w[i], j+1);
                bin[j] -= w[i];
                placed = 1;
                break;
            }
        }

        // If not placed, create new bin
        if(!placed) {
            bin[bins_used] = c - w[i];
            printf("Item %d (%d) placed in NEW Bin %d\n", i+1, w[i], bins_used+1);
            bins_used++;
        }
    }

    printf("\nTotal bins used = %d\n", bins_used);

    return 0;
}
