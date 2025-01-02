#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 8

void xorBlocks(char *block1, char *block2, char *result) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        result[i] = block1[i] ^ block2[i];
    }
}

void cbc_mac(char *key, char *message, char *mac) {
    char iv[BLOCK_SIZE] = {0};  // Initialization vector
    char temp[BLOCK_SIZE];
    int len = strlen(message) / BLOCK_SIZE;

    for (int i = 0; i < len; i++) {
        xorBlocks(message + i * BLOCK_SIZE, iv, temp);
        // Simulate encryption
        memcpy(iv, temp, BLOCK_SIZE);
    }
    memcpy(mac, iv, BLOCK_SIZE);
}

int main() {
    char key[BLOCK_SIZE] = "keyblock";
    char message[BLOCK_SIZE * 2] = "blockoneblocktwo";
    char mac[BLOCK_SIZE];

    cbc_mac(key, message, mac);
    printf("CBC-MAC for the two-block message: %s\n", mac);

    return 0;
}

