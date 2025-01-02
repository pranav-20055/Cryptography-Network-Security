#include <stdio.h>
#include <string.h>

void monoalphabeticCipher(char text[], char key[]) {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char offset = islower(text[i]) ? 'a' : 'A';
            int index = tolower(text[i]) - 'a';
            text[i] = islower(text[i]) ? key[index] : toupper(key[index]);
        }
    }
}

int main() {
    char text[100], key[27];
    printf("Enter text to encrypt: ");
    scanf("%[^\n]", text);
    printf("Enter substitution key (26 letters): ");
    scanf("%s", key);
    if (strlen(key) != 26) {
        printf("Invalid key! Key must contain 26 unique letters.\n");
        return 1;
    }
    monoalphabeticCipher(text, key);
    printf("Encrypted text: %s\n", text);
    return 0;
}

