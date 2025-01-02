#include <stdio.h>
#include <stdlib.h>

// Modular inverse function
int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1; // No modular inverse exists
}

// Matrix multiplication modulo 26
void matrixMultiply(int a[2][2], int b[2][2], int result[2][2], int mod) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
            result[i][j] %= mod;
        }
    }
}

// Finding the inverse of a 2x2 matrix modulo 26
void matrixInverse(int matrix[2][2], int inverse[2][2], int mod) {
    int det = (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) % mod;
    if (det < 0)
        det += mod;
    int detInv = modInverse(det, mod);

    inverse[0][0] = (matrix[1][1] * detInv) % mod;
    inverse[0][1] = (-matrix[0][1] * detInv) % mod;
    inverse[1][0] = (-matrix[1][0] * detInv) % mod;
    inverse[1][1] = (matrix[0][0] * detInv) % mod;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (inverse[i][j] < 0)
                inverse[i][j] += mod;
        }
    }
}

int main() {
    int plaintext[2][2] = {{7, 4}, {19, 8}}; // Example plaintext blocks
    int ciphertext[2][2] = {{15, 18}, {5, 24}}; // Corresponding ciphertext blocks

    int plaintextInverse[2][2], key[2][2];

    // Find the inverse of the plaintext matrix
    matrixInverse(plaintext, plaintextInverse, 26);

    // Calculate the key matrix
    matrixMultiply(ciphertext, plaintextInverse, key, 26);

    printf("Derived Key Matrix:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", key[i][j]);
        }
        printf("\n");
    }

    return 0;
}

