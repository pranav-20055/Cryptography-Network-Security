#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ALPHABET_SIZE 26

// Encrypt with one-time pad
void encrypt(const char *plaintext, const int *key, char *ciphertext) {
    size_t len = strlen(plaintext);
    for (size_t i = 0; i < len; i++) {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = ((plaintext[i] - 'a' + key[i]) % ALPHABET_SIZE) + 'a';
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = ((plaintext[i] - 'A' + key[i]) % ALPHABET_SIZE) + 'A';
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[len] = '\0';
}

int main() {
    const char *plaintext = "send more money";
    int key[] = {9, 0, 17, 23, 15, 21, 14, 11, 11, 2, 8, 9};
    char ciphertext[256];

    encrypt(plaintext, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}

