#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Function to calculate modular exponentiation
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

// Function to encrypt a message
void encryptMessage(char *plaintext, int e, int n, int *ciphertext) {
    for (int i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = modExp(plaintext[i] - 'A', e, n);  // Map A-Z to 0-25
    }
}

// Function to decrypt a message
void decryptMessage(int *ciphertext, int len, int d, int n, char *plaintext) {
    for (int i = 0; i < len; i++) {
        plaintext[i] = modExp(ciphertext[i], d, n) + 'A';  // Map 0-25 to A-Z
    }
    plaintext[len] = '\0';
}

int main() {
    char plaintext[] = "HELLO";
    int e = 7, d = 103, n = 143;  // Example RSA keys
    int ciphertext[ALPHABET_SIZE];
    char decrypted[ALPHABET_SIZE];

    printf("Plaintext: %s\n", plaintext);

    // Encrypt
    encryptMessage(plaintext, e, n, ciphertext);
    printf("Ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++) {
        printf("%d ", ciphertext[i]);
    }
    printf("\n");

    // Decrypt
    decryptMessage(ciphertext, strlen(plaintext), d, n, decrypted);
    printf("Decrypted: %s\n", decrypted);

    // Frequency analysis weakness
    printf("\nSecurity Weakness:\n");
    printf("If each letter is encrypted independently, an attacker can perform frequency analysis.\n");
    printf("For example, 'E' is the most common letter, making its ciphertext easy to identify.\n");

    return 0;
}

