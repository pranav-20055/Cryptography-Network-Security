#include <stdio.h>

// Function to calculate GCD
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int n = 3599;  // Example modulus
    int plaintext_block = 1234;  // Example plaintext block
    int factor = gcd(n, plaintext_block);

    if (factor > 1 && factor < n) {
        printf("Common factor found: %d\n", factor);
        printf("Other factor: %d\n", n / factor);
    } else {
        printf("No common factor found with n = %d and plaintext block = %d\n", n, plaintext_block);
    }

    return 0;
}

