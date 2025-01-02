#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 8

// Padding function
void pad(char *input, char *output, int blockSize) {
    int len = strlen(input);
    int pad_len = blockSize - (len % blockSize);
    strcpy(output, input);
    for (int i = 0; i < pad_len; i++) {
        output[len + i] = (i == 0) ? '1' : '0'; // Add 1 followed by 0s.
    }
    output[len + pad_len] = '\0';
}

void ecb_mode(char *plaintext, char *ciphertext) {
    printf("ECB Mode - Plaintext: %s\n", plaintext);
    strcpy(ciphertext, plaintext); // Dummy encryption.
}

void cbc_mode(char *plaintext, char *ciphertext, char *iv) {
    printf("CBC Mode - Plaintext: %s\n", plaintext);
    // Dummy encryption: XOR with IV for the first block.
    for (int i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = plaintext[i] ^ iv[i % BLOCK_SIZE];
    }
    ciphertext[strlen(plaintext)] = '\0';
}

void cfb_mode(char *plaintext, char *ciphertext, char *iv) {
    printf("CFB Mode - Plaintext: %s\n", plaintext);
    // Dummy encryption: XOR with IV for each byte.
    for (int i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = plaintext[i] ^ iv[i % BLOCK_SIZE];
    }
    ciphertext[strlen(plaintext)] = '\0';
}

int main() {
    char plaintext[256] = "This is a test message.";
    char padded_text[256];
    char ciphertext[256];
    char iv[BLOCK_SIZE] = "IVBLOCK1";

    // Pad plaintext
    pad(plaintext, padded_text, BLOCK_SIZE);

    // ECB mode
    ecb_mode(padded_text, ciphertext);
    printf("Ciphertext (ECB): %s\n", ciphertext);

    // CBC mode
    cbc_mode(padded_text, ciphertext, iv);
    printf("Ciphertext (CBC): %s\n", ciphertext);

    // CFB mode
    cfb_mode(padded_text, ciphertext, iv);
    printf("Ciphertext (CFB): %s\n", ciphertext);

    return 0;
}

