#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of shifts for each round
int shift_schedule[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

// Function to perform left circular shift
void left_circular_shift(char *key, int shifts) {
    int len = strlen(key);
    char temp[len];
    strcpy(temp, key);
    for (int i = 0; i < len; i++) {
        key[i] = temp[(i + shifts) % len];
    }
}

// Function to generate keys for decryption
void generate_decryption_keys(char *initial_key, char keys[16][56]) {
    char current_key[56];
    strcpy(current_key, initial_key);

    // Generate encryption keys
    for (int i = 0; i < 16; i++) {
        left_circular_shift(current_key, shift_schedule[i]);
        strcpy(keys[i], current_key);
    }

    // Reverse the order of keys for decryption
    for (int i = 0; i < 8; i++) {
        char temp[56];
        strcpy(temp, keys[i]);
        strcpy(keys[i], keys[15 - i]);
        strcpy(keys[15 - i], temp);
    }
}

int main() {
    char initial_key[56] = "101010101011101100001001000110000010011100110110";
    char keys[16][56];

    generate_decryption_keys(initial_key, keys);

    printf("Decryption Keys:\n");
    for (int i = 0; i < 16; i++) {
        printf("K%d: %s\n", i + 1, keys[i]);
    }

    return 0;
}

