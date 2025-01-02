#include <stdio.h>
#include <string.h>
#include <ctype.h>

void preprocessPlaintext(char plaintext[]) {
    int len = strlen(plaintext);
    char processed[100];
    int index = 0;

    for (int i = 0; i < len; i++) {
        if (isalpha(plaintext[i])) {
            processed[index++] = toupper(plaintext[i]);
        }
    }

    processed[index] = '\0';

    // Insert 'X' between repeated letters in a pair
    char finalText[100];
    index = 0;
    for (int i = 0; i < strlen(processed); i++) {
        finalText[index++] = processed[i];
        if (i + 1 < strlen(processed) && processed[i] == processed[i + 1]) {
            finalText[index++] = 'X';
        }
    }
    if (index % 2 != 0) {
        finalText[index++] = 'X';  // Add 'X' to make length even
    }
    finalText[index] = '\0';
    strcpy(plaintext, finalText);
}

void encryptPlayfair(char plaintext[], char matrix[5][5]) {
    int row1, col1, row2, col2;
    int len = strlen(plaintext);

    for (int i = 0; i < len; i += 2) {
        char first = plaintext[i];
        char second = plaintext[i + 1];

        // Locate the letters in the matrix
        for (int row = 0; row < 5; row++) {
            for (int col = 0; col < 5; col++) {
                if (matrix[row][col] == first) {
                    row1 = row;
                    col1 = col;
                }
                if (matrix[row][col] == second) {
                    row2 = row;
                    col2 = col;
                }
            }
        }

        // Encrypt using Playfair rules
        if (row1 == row2) {  // Same row
            plaintext[i] = matrix[row1][(col1 + 1) % 5];
            plaintext[i + 1] = matrix[row2][(col2 + 1) % 5];
        } else if (col1 == col2) {  // Same column
            plaintext[i] = matrix[(row1 + 1) % 5][col1];
            plaintext[i + 1] = matrix[(row2 + 1) % 5][col2];
        } else {  // Rectangle
            plaintext[i] = matrix[row1][col2];
            plaintext[i + 1] = matrix[row2][col1];
        }
    }
}

int main() {
    char matrix[5][5] = {
        {'M', 'F', 'H', 'I', 'J'},
        {'K', 'U', 'N', 'O', 'P'},
        {'Q', 'Z', 'V', 'W', 'X'},
        {'Y', 'E', 'L', 'A', 'R'},
        {'G', 'D', 'S', 'T', 'B'}
    };

    char plaintext[100] = "Must see you over Cadogan West. Coming at once.";
    preprocessPlaintext(plaintext);

    printf("Preprocessed plaintext: %s\n", plaintext);

    encryptPlayfair(plaintext, matrix);

    printf("Encrypted text: %s\n", plaintext);

    return 0;
}

