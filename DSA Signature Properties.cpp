#include <stdio.h>

// Modular exponentiation
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    long long p = 23, q = 11, g = 2;  // Example DSA parameters
    long long x = 6;                  // Private key
    long long k1 = 3, k2 = 3;         // Same k used twice
    long long h1 = 5, h2 = 8;         // Hashes of different messages

    // Compute r for both messages
    long long r1 = modExp(g, k1, p) % q;
    long long r2 = modExp(g, k2, p) % q;

    // Compute s for both messages
    long long s1 = (h1 + x * r1) * modExp(k1, q - 2, q) % q;
    long long s2 = (h2 + x * r2) * modExp(k2, q - 2, q) % q;

    printf("Signature 1: r = %lld, s = %lld\n", r1, s1);
    printf("Signature 2: r = %lld, s = %lld\n", r2, s2);

    // Implication of using the same k
    printf("\nImplication:\n");
    printf("Using the same k reveals the private key. The adversary can compute:\n");
    printf("x = ((s1 - s2) * (h1 - h2)^-1) mod q\n");

    return 0;
}

