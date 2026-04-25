#include <stdio.h>

int main() {
    int n, i;
    int a = 0, b = 1, next;

    printf("Enter n: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("Nth Fibonacci term = 0\n");
        return 0;
    }

    for (i = 2; i <= n; i++) {
        next = a + b;
        a = b;
        b = next;
    }

    printf("Nth Fibonacci term = %d\n", b);
    return 0;
}
