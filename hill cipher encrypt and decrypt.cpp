#include <stdio.h>
#include <string.h>

#define SIZE 2

void encrypt(int key[SIZE][SIZE], char *plaintext, char *ciphertext) {
    int i, j, k, block[SIZE], cipherBlock[SIZE];
    int len = strlen(plaintext);
    for (i = 0; i < len; i += SIZE) {
        for (j = 0; j < SIZE; j++) 
            block[j] = plaintext[i + j] - 'a';
        for (j = 0; j < SIZE; j++) {
            cipherBlock[j] = 0;
            for (k = 0; k < SIZE; k++)
                cipherBlock[j] += key[j][k] * block[k];
            cipherBlock[j] %= 26;
        }
        for (j = 0; j < SIZE; j++)
            ciphertext[i + j] = cipherBlock[j] + 'a';
    }
}

int main() {
    int key[SIZE][SIZE] = {{9, 4}, {5, 7}};
    char plaintext[] = "meetmeattheusualplaceattenratherthaneoclock";
    char ciphertext[100];
    encrypt(key, plaintext, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}

