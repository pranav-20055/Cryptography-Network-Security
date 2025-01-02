#include <stdio.h>
#include <string.h>

void ecb_mode(const unsigned char *key, const unsigned char *plaintext, unsigned char *ciphertext, int len) {
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 128, &aes_key);
    for (int i = 0; i < len; i += AES_BLOCK_SIZE) {
        AES_encrypt(plaintext + i, ciphertext + i, &aes_key);
    }
}

// Function to encrypt in CBC mode
void cbc_mode(const unsigned char *key, const unsigned char *plaintext, unsigned char *ciphertext, int len, unsigned char *iv) {
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 128, &aes_key);
    AES_cbc_encrypt(plaintext, ciphertext, len, &aes_key, iv, AES_ENCRYPT);
}

int main() {
    const unsigned char key[16] = "thisisakey123456";
    const unsigned char plaintext[32] = "This is a secret message!";
    unsigned char ecb_ciphertext[32], cbc_ciphertext[32];
    unsigned char cbc_iv[16] = "1234567890123456";

    printf("Plaintext: %s\n", plaintext);

    // ECB Mode
    ecb_mode(key, plaintext, ecb_ciphertext, 32);
    printf("\nECB Encrypted Text: ");
    for (int i = 0; i < 32; i++) {
        printf("%02x", ecb_ciphertext[i]);
    }

    // CBC Mode
    cbc_mode(key, plaintext, cbc_ciphertext, 32, cbc_iv);
    printf("\n\nCBC Encrypted Text: ");
    for (int i = 0; i < 32; i++) {
        printf("%02x", cbc_ciphertext[i]);
    }

    printf("\n\nError Propagation:\n");
    printf("- In ECB, an error affects only the corresponding block.\n");
    printf("- In CBC, an error propagates to the next block as well.\n");

    return 0;
}

