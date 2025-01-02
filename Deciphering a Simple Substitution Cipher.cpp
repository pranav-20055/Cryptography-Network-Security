#include <stdio.h>
#include <string.h>
#include <ctype.h>

void decryptSubstitution(char ciphertext[], char mapping[]) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            ciphertext[i] = mapping[tolower(ciphertext[i]) - 'a'];
        }
    }
}

int main() {
    char ciphertext[] = "531305))6:4826)41.)41);806*:48+860))85;;]8*;:*8+83 (88)...";  // Replace with full ciphertext
    char mapping[26] = {'e', 't', 'a', 'o', 'i', 'n', 's', 'r', 'h', 'd', 'l', 'c', 'u', 'm', 'w', 'f', 'g', 'y', 'p', 'b', 'v', 'k', 'j', 'x', 'q', 'z'};
    decryptSubstitution(ciphertext, mapping);
    printf("Decrypted text: %s\n", ciphertext);
    return 0;
}

