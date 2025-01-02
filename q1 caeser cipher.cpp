#include <stdio.h>
#include <ctype.h>

void caesarCipher(char text[], int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (isalpha(ch)) {
            char offset = isupper(ch) ? 'A' : 'a';
            text[i] = ((ch - offset + key) % 26) + offset;
        }
    }
}

int main() {
    char text[100];
    int key;
    printf("Enter text to encrypt: ");
    scanf("%[^\n]", text);
    printf("Enter key (1-25): ");
    scanf("%d", &key);
    if (key < 1 || key > 25) {
    	
        printf("Invalid key! Key must be in the range 1-25.\n");
        return 1;
    }
    caesarCipher(text, key);
    printf("Encrypted text: %s\n", text);
    return 0;
}


