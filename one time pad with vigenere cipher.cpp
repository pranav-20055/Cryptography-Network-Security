#include <stdio.h>
#include <string.h>

void vigenere_encrypt(char *plaintext, int *key, char *ciphertext, int keyLen) {
    int i, len = strlen(plaintext);
    for (i = 0; i < len; i++) {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = ((plaintext[i] - 'a') + key[i % keyLen]) % 26 + 'a';
        } else {
            ciphertext[i] = plaintext[i]; // Preserve spaces and non-alphabet characters
        }
    }
    ciphertext[len] = '\0';
}

void vigenere_decrypt(char *ciphertext, int *key, char *plaintext, int keyLen) {
    int i, len = strlen(ciphertext);
    for (i = 0; i < len; i++) {
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            plaintext[i] = ((ciphertext[i] - 'a') - key[i % keyLen] + 26) % 26 + 'a';
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[len] = '\0';
}

int main() {
    char plaintext[] = "sendmoremoney";
    int key[] = {9, 0, 17, 23, 15, 21, 14, 11, 11, 2, 8, 9};
    char ciphertext[100], decrypted[100];
    int keyLen = 12;

    // Encrypt
    vigenere_encrypt(plaintext, key, ciphertext, keyLen);
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt
    vigenere_decrypt(ciphertext, key, decrypted, keyLen);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}

