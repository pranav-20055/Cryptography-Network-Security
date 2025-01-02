#include <stdio.h>

// Function to compute modular exponentiation
int modExp(int base, int exp, int mod) {
    int result = 1;
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
    int a = 5, q = 23, xA = 6, xB = 15;

    // Correct exchange
    int aliceSends = modExp(a, xA, q);
    int bobSends = modExp(a, xB, q);

    // Shared key
    int aliceKey = modExp(bobSends, xA, q);
    int bobKey = modExp(aliceSends, xB, q);

    printf("Shared key (correct protocol): %d\n", aliceKey);

    // Incorrect exchange (x^a)
    printf("If participants exchange x^a, modular exponentiation fails to provide security.\n");
    return 0;
}

