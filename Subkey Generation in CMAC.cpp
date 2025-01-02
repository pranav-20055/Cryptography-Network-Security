#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define BLOCK_SIZE_128 128
#define BLOCK_SIZE_64 64

// XOR two byte arrays
void xorBytes(uint8_t *out, uint8_t *in1, uint8_t *in2, int len) {
    for (int i = 0; i < len; i++) {
        out[i] = in1[i] ^ in2[i];
    }
}

// Left shift a byte array by 1 bit
void leftShift(uint8_t *out, uint8_t *in, int len) {
    uint8_t carry = 0;
    for (int i = len - 1; i >= 0; i--) {
        uint8_t next_carry = in[i] >> 7;
        out[i] = (in[i] << 1) | carry;
        carry = next_carry;
    }
}

// CMAC subkey generation
void generateCMACSubkeys(uint8_t *k1, uint8_t *k2, int blockSize) {
    uint8_t L[16] = {0};  // Simulated output of AES(0)
    uint8_t Rb[16];       // Polynomial for GF(2^blockSize)

    // Constants for different block sizes
    if (blockSize == BLOCK_SIZE_128) {
        memcpy(Rb, (uint8_t[]){0x87, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                               0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
               16);
    } else if (blockSize == BLOCK_SIZE_64) {
        memcpy(Rb, (uint8_t[]){0x1B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 8);
    } else {
        printf("Unsupported block size.\n");
        return;
    }

    // Step 1: Compute K1
    leftShift(k1, L, blockSize / 8);
    if (L[0] & 0x80) {  // If MSB is 1
        xorBytes(k1, k1, Rb, blockSize / 8);
    }

    // Step 2: Compute K2
    leftShift(k2, k1, blockSize / 8);
    if (k1[0] & 0x80) {
        xorBytes(k2, k2, Rb, blockSize / 8);
    }
}

int main() {
    uint8_t k1[16], k2[16];

    printf("Generating subkeys for 128-bit block size...\n");
    generateCMACSubkeys(k1, k2, BLOCK_SIZE_128);
    printf("K1: ");
    for (int i = 0; i < 16; i++) printf("%02X ", k1[i]);
    printf("\nK2: ");
    for (int i = 0; i < 16; i++) printf("%02X ", k2[i]);
    printf("\n");

    return 0;
}

