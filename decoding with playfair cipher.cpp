#include <stdio.h>
#include <string.h>

void generateMatrix(char key[], char matrix[5][5]) {
    int used[26] = {0};
    int index = 0;

    // Add the keyword
    for (int i = 0; key[i] != '\0'; i++) {
        if (!used[toupper(key[i]) - 'A'] && key[i] != 'J') {
            matrix[index / 5][index % 5] = toupper(key[i]);
            used[toupper(key[i]) - 'A'] = 1;
            index++;
        }
    }

    // Add remaining letters
    for (char c = 'A'; c <= 'Z'; c++) {
        if (!used[c - 'A'] && c != 'J') {
            matrix[index / 5][index % 5] = c;
            used[c - 'A'] = 1;
            index++;
        }
    }
}

void decryptPlayfair(char ciphertext[], char matrix[5][5]) {
    int i, j, row1, col1, row2, col2;

    for (int k = 0; ciphertext[k] != '\0'; k += 2) {
        char first = ciphertext[k];
        char second = ciphertext[k + 1];

        // Locate letters in the matrix
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (matrix[i][j] == first) {
                    row1 = i;
                    col1 = j;
                }
                if (matrix[i][j] == second) {
                    row2 = i;
                    col2 = j;
                }
            }
        }

        // Decode using Playfair rules
        if (row1 == row2) {  // Same row
            ciphertext[k] = matrix[row1][(col1 + 4) % 5];
            ciphertext[k + 1] = matrix[row2][(col2 + 4) % 5];
        } else if (col1 == col2) {  // Same column
            ciphertext[k] = matrix[(row1 + 4) % 5][col1];
            ciphertext[k + 1] = matrix[(row2 + 4) % 5][col2];
        } else {  // Rectangle
            ciphertext[k] = matrix[row1][col2];
            ciphertext[k + 1] = matrix[row2][col1];
        }
    }
}

int main() {
    char key[] = "KXJEY";
    char ciphertext[] = "UREBEZWEHEWRYTUHEYFS...";
    char matrix[5][5];

    generateMatrix(key, matrix);
    decryptPlayfair(ciphertext, matrix);

    printf("Decrypted text: %s\n", ciphertext);
    return 0;
}

