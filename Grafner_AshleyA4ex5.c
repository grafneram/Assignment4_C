//Ashley Grafner
//9/17/2024
//"Write recursive functions for factorial and permutations"

#include <stdio.h>

int factorial(int i);

int permutations(int i, int r);

int main() {
    int choice, n, r;

    // Ask user for choice
    printf("Choose an option:\n");
    printf("1. Calculate Factorial\n");
    printf("2. Calculate Permutations\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            // Get number for factorial
                printf("Enter a number to calculate factorial: ");
        scanf("%d", &n);
        if (n < 0) {
            printf("Factorial is not defined for negative numbers.\n");
        } else {
            printf("Factorial of %d is %d\n", n, factorial(n));
        }
        break;
        case 2:
            // Get numbers for permutations
                printf("Enter the total number of items (n): ");
        scanf("%d", &n);
        printf("Enter the number of items to choose (r): ");
        scanf("%d", &r);
        if (n < 0 || r < 0) {
            printf("Permutation is not defined for negative numbers.\n");
        } else if (r > n) {
            printf("Number of items to choose cannot be greater than the total number of items.\n");
        } else {
            printf("Number of permutations of %d items taken %d at a time is %d\n", n, r, permutations(n, r));
        }
        break;
        default:
            printf("Invalid choice.\n");
        break;
    }

    return 0;
}

// Function to calculate factorial recursively
int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate permutations recursively
int permutations(int n, int r) {
    if (r > n) {
        return 0;
    }
    return factorial(n) / factorial(n - r);
}