#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n, int selectedItems[]) {
    int i, w;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w) {
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            } else {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    i = n;
    w = W;
    int index = 0;

    while (i > 0 && w > 0) {
        if (K[i][w] != K[i - 1][w]) {
            selectedItems[index++] = i - 1;
            w -= wt[i - 1];
            i--;
        } else {
            i--;
        }
    }

    return K[n][W];
}

int main() {
    int n, W;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int val[n], wt[n], selectedItems[n];

    printf("Enter the values of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d", &val[i]);
    }

    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d", &wt[i]);
    }

    printf("Enter the maximum weight capacity: ");
    scanf("%d", &W);

    int maxVal = knapsack(W, wt, val, n, selectedItems);

    printf("Maximum value that can be obtained = %d\n", maxVal);

    printf("Items selected in the knapsack:\n");
    for (int i = maxVal - 1; i >= 0; i--) {
        printf("Item %d - Value: %d, Weight: %d\n", selectedItems[i] + 1, val[selectedItems[i]], wt[selectedItems[i]]);
    }

    return 0;
}
