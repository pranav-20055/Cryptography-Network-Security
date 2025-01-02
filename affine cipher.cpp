#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void affineCipher(char text[], int a, int b) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char offset = islower(text[i]) ? 'a' : 'A';
            text[i] = ((a * (text[i] - offset) + b) % 26 + 26) % 26 + offset;
        }
    }
}

int main() {
    char text[100];
    int a, b;
    printf("Enter text to encrypt: ");
    scanf("%[^\n]", text);
    printf("Enter a (must be coprime with 26): ");
    scanf("%d", &a);
    printf("Enter b: ");
    scanf("%d", &b);
    if (gcd(a, 26) != 1) {
        printf("Invalid value for a! It must be coprime with 26.\n");
        return 1;
    }
    affineCipher(text, a, b);
    printf("Encrypted text: %s\n", text);
    return 0;
}

