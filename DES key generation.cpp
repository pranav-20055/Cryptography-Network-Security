#include <stdio.h>
#include <string.h>

// Define Permutation Tables
int perm1[56] = {
    57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18,
    10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36,
    63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22,
    14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4
};
int perm2[48] = {
    14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19,
    12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37,
    47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53,
    46, 42, 50, 36, 29, 32
};

// Function to apply a permutation
void apply_permutation(const int *perm_table, int perm_size, char *input, char *output) {
    for (int i = 0; i < perm_size; i++) {
        output[i] = input[perm_table[i] - 1];
    }
    output[perm_size] = '\0';
}

// Function to generate subkeys
void generate_subkeys(char *initial_key, char subkeys[16][48]) {
    char permuted_key[56], left[28], right[28];
    char combined[56], compressed[48];

    // Apply initial permutation
    apply_permutation(perm1, 56, initial_key, permuted_key);

    // Split into left and right halves
    strncpy(left, permuted_key, 28);
    strncpy(right, permuted_key + 28, 28);

    // Generate 16 subkeys
    for (int round = 0; round < 16; round++) {
        left_circular_shift(left, shift_schedule[round]);
        left_circular_shift(right, shift_schedule[round]);

        // Combine halves and apply compression permutation
        snprintf(combined, 56, "%s%s", left, right);
        apply_permutation(perm2, 48, combined, compressed);

        strcpy(subkeys[round], compressed);
    }
}

int main() {
    char initial_key[64] = "0001001100110100010101110111100110011011101111001101111111110001";
    char subkeys[16][48];

    generate_subkeys(initial_key, subkeys);

    printf("Generated Subkeys:\n");
    for (int i = 0; i < 16; i++) {
        printf("K%d: %s\n", i + 1, subkeys[i]);
    }

    return 0;
}

