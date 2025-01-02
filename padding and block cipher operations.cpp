#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define BLOCK_SIZE 16

// Example encryption function (block cipher)
void encryptBlock(uint8_t *block, uint8_t *key) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        block[i] ^= key[i];
    }
}

// ECB Mode
void ecbEncrypt(uint8_t *data, size_t len, uint8_t *key) {
    for (size_t i = 0; i < len; i += BLOCK_SIZE) {
        encryptBlock(data + i, key);
    }
}

// CBC Mode
void cbcEncrypt(uint8_t *data, size_t len, uint8_t *key, uint8_t *iv) {
    uint8_t prev[BLOCK_SIZE];
    memcpy(prev, iv, BLOCK_SIZE);

    for (size_t i = 0; i < len; i += BLOCK_SIZE) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            data[i + j] ^= prev[j];
        }
        encryptBlock(data + i, key);
        memcpy(prev, data + i, BLOCK_SIZE);
    }
}

// Padding function
void pad(uint8_t *data, size_t *len) {
    size_t padLen = BLOCK_SIZE - (*len % BLOCK_SIZE);
    for (size_t i = 0; i < padLen; i++) {
        data[*len + i] = padLen;
    }
    *len += padLen;
}

int main() {
    uint8_t data[64] = "This is a test message.";
    size_t dataLen = strlen((char *)data);
    uint8_t key[BLOCK_SIZE] = {0};
    uint8_t iv[BLOCK_SIZE] = {0};

    pad(data, &dataLen);

    printf("Encrypting with ECB mode...\n");
    ecbEncrypt(data, dataLen, key);
    printf("Ciphertext: ");
    for (size_t i = 0; i < dataLen; i++) {
        printf("%02X ", data[i]);
    }
    printf("\n");

    return 0;
}

