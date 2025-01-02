#include <stdio.h>
#include <string.h>

// English letter frequency order (most to least frequent)
const char frequency_order[] = "etaoinshrdlcumwfgypbvkjxqz";

// Function to decrypt with a given key
void decrypt_additive_cipher(char *ciphertext, char *plaintext, int key) {
    int len = strlen(ciphertext);
    for (int i = 0; i < len; i++) {
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            plaintext[i] = ((ciphertext[i] - 'a' - key + 26) % 26) + 'a';
        } else {
            plaintext[i] = ciphertext[i]; // Preserve non-alphabet characters
        }
    }
    plaintext[len] = '\0';
}

// Frequency attack on additive cipher
void frequency_attack(char *ciphertext, int topN) {
    char plaintext[100];
    printf("Top %d possible plaintexts:\n", topN);
    for (int key = 0; key < 26 && key < topN; key++) {
        decrypt_additive_cipher(ciphertext, plaintext, key);
        printf("Key %2d: %s\n", key, plaintext);
    }
}

int main() {
    char ciphertext[] = "wklv lv d whvw phvvdjh"; // Example ciphertext
    int topN = 10; // Show top 10 plaintexts
    frequency_attack(ciphertext, topN);
    return 0;
}

