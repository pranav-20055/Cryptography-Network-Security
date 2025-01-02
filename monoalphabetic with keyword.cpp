#include <stdio.h>
#include <string.h>
#include <ctype.h>

void generateCipherSequence(char keyword[], char cipher[]) {
    int used[26] = {0};
    int index = 0;

    // Add keyword characters to cipher
    for (int i = 0; keyword[i] != '\0'; i++) {
        char ch = toupper(keyword[i]);
        if (!used[ch - 'A']) {
            cipher[index++] = ch;
            used[ch - 'A'] = 1;
        }
    }

    // Add remaining letters
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (!used[ch - 'A']) {
            cipher[index++] = ch;
        }
    }
    cipher[index] = '\0';
}

void encryptMonoalphabetic(char plaintext[], char cipher[], char encrypted[]) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            char offset = isupper(plaintext[i]) ? 'A' : 'a';
            encrypted[i] = cipher[plaintext[i] - offset];
        } else {
            encrypted[i] = plaintext[i];
        }
    }
    encrypted[strlen(plaintext)] = '\0';
}

int main() {
    char keyword[100], plaintext[100], cipher[27], encrypted[100];
    printf("Enter keyword: ");
    scanf("%s", keyword);
    getchar(); // To consume newline after the keyword
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    generateCipherSequence(keyword, cipher);
    encryptMonoalphabetic(plaintext, cipher, encrypted);

    printf("Cipher sequence: %s\n", cipher);
    printf("Encrypted text: %s\n", encrypted);

    return 0;
}

