#include <stdio.h>
#include <ctype.h>

int modularInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

void decryptAffine(char cipher[], int a, int b) {
    int a_inv = modularInverse(a, 26);
    if (a_inv == -1) {
        printf("Error: No modular inverse for a = %d.\n", a);
        return;
    }
    for (int i = 0; cipher[i] != '\0'; i++) {
        if (isalpha(cipher[i])) {
            char offset = isupper(cipher[i]) ? 'A' : 'a';
            cipher[i] = ((a_inv * (cipher[i] - offset - b + 26)) % 26) + offset;
        }
    }
}

int main() {
    char ciphertext[] = "B...U...";  // Replace with the actual ciphertext
    int a = 15;  // From solving the equations
    int b = 5;   // From solving the equations
    decryptAffine(ciphertext, a, b);
    printf("Decrypted text: %s\n", ciphertext);
    return 0;
}

