#include <stdio.h>
#include <string.h>

void cbc_encrypt_decrypt(const char *plaintext, const char *key1, const char *key2, const char *key3, unsigned char *iv) {
    DES_key_schedule ks1, ks2, ks3;
    unsigned char ciphertext[1024], decryptedtext[1024];
    int len = strlen(plaintext);

    // Set up keys
    memcpy(key_block1, key1, 8);
    memcpy(key_block2, key2, 8);
    memcpy(key_block3, key3, 8);
    DES_set_key(&key_block1, &ks1);
    DES_set_key(&key_block2, &ks2);
    DES_set_key(&key_block3, &ks3);

    // Encrypt
    DES_ede3_cbc_encrypt((unsigned char *)plaintext, ciphertext, len + 1, &ks1, &ks2, &ks3, &iv, DES_ENCRYPT);
    printf("Encrypted text: ");
    for (int i = 0; i < len + 1; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Decrypt
    DES_ede3_cbc_encrypt(ciphertext, decryptedtext, len + 1, &ks1, &ks2, &ks3, &iv, DES_DECRYPT);
    printf("Decrypted text: %s\n", decryptedtext);
}

int main() {
    const char *plaintext = "Encrypt this text using CBC mode";
    const char *key1 = "key12345";
    const char *key2 = "key67890";
    const char *key3 = "keyABCDE";
    unsigned char iv[8] = "12345678";

    cbc_encrypt_decrypt(plaintext, key1, key2, key3, iv);
    return 0;
}

