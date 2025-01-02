#include <stdio.h>

// Extended Euclidean Algorithm to find modular inverse
int gcdExtended(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

// Function to find modular inverse
int modInverse(int a, int m) {
    int x, y;
    int gcd = gcdExtended(a, m, &x, &y);
    if (gcd != 1)
        return -1;  // Inverse doesn't exist
    return (x % m + m) % m;
}

int main() {
    int p = 61, q = 53;  // Example primes
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    int leaked_d = 2753;  // Example leaked private key
    printf("Leaked private key (d): %d\n", leaked_d);

    // Calculate public key e
    int e = modInverse(leaked_d, phi);
    if (e == -1) {
        printf("Failed to compute new public key.\n");
        return 1;
    }
    printf("Computed new public key (e): %d\n", e);

    // Attempt to regenerate keys
    int new_d = modInverse(e, phi);
    printf("Regenerated private key (d): %d\n", new_d);

    // Insecurity analysis
    printf("Key regeneration is insecure because the leaked private key allows factorization of n (%d).\n", n);
    printf("Once p and q are known, any key can be computed.\n");

    return 0;
}

