#include <stdio.h>

int add(int *a, int *b, int *c) {
    return *a + *b + *c;
}

int main() {
    int x, y, z, sum;

    printf("Enter three integers: ");
    scanf("%d %d %d", &x, &y, &z);

    // Call the add function and store the result
    sum = add(&x, &y, &z);

    // Print the result
    printf("The sum of %d, %d, and %d is: %d\n", x, y, z, sum);

    return 0;
}
