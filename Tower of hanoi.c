#include <stdio.h>

// Function to solve Tower of Hanoi
void hanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    // Move n-1 disks from source to auxiliary
    hanoi(n - 1, source, destination, auxiliary);

    // Move nth disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);

    // Move n-1 disks from auxiliary to destination
    hanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    hanoi(n, 'A', 'B', 'C');

    return 0;
}
