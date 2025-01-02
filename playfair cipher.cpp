#include <stdio.h>
#include <string.h>
#include <ctype.h>

void createMatrix(char key[], char matrix[5][5]) {
    int used[26] = {0};
    int k = 0, i = 0, j = 0;
    for (int n = 0; key[n] != '\0'; n++) {
        if (!used[key[n] - 'a'] && key[n] != 'j') {
            matrix[i][j++] = key[n];
            used[key[n] - 'a'] = 1;
            if (j == 5) { i++; j = 0; }
        }
    }
    for (char c = 'a'; c <= 'z'; c++) {
        if (!used[c - 'a'] && c != 'j') {
            matrix[i][j++] = c;
            used[c - 'a'] = 1;
            if (j == 5) { i++; j = 0; }
        }
    }
}

void encryptPair(char a, char b, char matrix[5][5], char *res) {
    int row1, col1, row2, col2;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == a) { row1 = i; col1 = j; }
            if (matrix[i][j] == b) { row2 = i; col2 = j; }
        }
    }
    if (row1 == row2) {
        res[0] = matrix[row1][(col1 + 1) % 5];
        res[1] = matrix[row2][(col2 + 1) % 5];
    } else if (col1 == col2) {
        res[0] = matrix[(row1 + 1) % 5][col1];
        res[1] = matrix[(row2 + 1) % 5][col2];
    } else {
        res[0] = matrix[row1][col2];
        res[1] = matrix[row2][col1];
    }
}

int main() {
    char key[100], text[100], matrix[5][5], result[200] = {0};
    printf("Enter keyword: ");
    scanf("%s", key);
    printf("Enter plaintext: ");
    scanf("%s", text);
    createMatrix(key, matrix);
    int len = strlen(text);
    for (int i = 0; i < len; i += 2) {
        char a = text[i], b = (i + 1 < len) ? text[i + 1] : 'x';
        if (a == b) b = 'x';
        encryptPair(a, b, matrix, result + i);
    }
    printf("Encrypted text: %s\n", result);
    return 0;
}

