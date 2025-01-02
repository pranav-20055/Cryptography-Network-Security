#include <stdio.h>
#include <string.h>

void polyalphabeticCipher(char text[], char key[]) {
    int keyLen = strlen(key);
    for (int i = 0, j = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])){
            char offset = isupper(text[i]) ? 'A' : 'a';
            char keyOffset = tolower(key[j % keyLen]) - 'a';
            text[i] = ((text[i] - offset + keyOffset) % 26) + offset;
            j++;
        }
    }
}

int main() {
    char text[100], key[100];
    printf("Enter text to encrypt: ");
    scanf("%[^\n]", text);
    printf("Enter key: ");
    scanf("%s", key);
    polyalphabeticCipher(text, key);
    printf("Encrypted text: %s\n", text);
    return 0;
}

