#include <stdio.h>
#include <string.h>

// Frequency order of letters in English
const char english_frequency[] = "etaoinshrdlcumwfgypbvkjxqz";

// Function to count letter frequencies
void count_frequencies(char *text, int *freq) {
    for (int i = 0; i < 26; i++) freq[i] = 0;
    for (int i = 0; text[i]; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            freq[text[i] - 'a']++;
        }
    }
}

// Sort frequencies and generate substitution map
void generate_substitution_map(int *freq, char *map) {
    int index[26];
    for (int i = 0; i < 26; i++) index[i] = i;

    // Sort index based on frequency (descending order)
    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            if (freq[index[j]] > freq[index[i]]) {
                int temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }
        }
    }

    // Map sorted frequencies to English frequency order
    for (int i = 0; i < 26; i++) {
        map[index[i]] = english_frequency[i];
    }
}

// Decrypt using substitution map
void decrypt_substitution(char *ciphertext, char *plaintext, char *map) {
    for (int i = 0; ciphertext[i]; i++) {
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            plaintext[i] = map[ciphertext[i] - 'a'];
        } else {
            plaintext[i] = ciphertext[i]; // Preserve non-alphabet characters
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
}

int main() {
    char ciphertext[] = "jxu evviuj veh jxu iusedt cuiiqwu yi vekhju"; // Example ciphertext
    char plaintext[100];
    int freq[26];
    char map[26];

    count_frequencies(ciphertext, freq);

    // Generate substitution map
    generate_substitution_map(freq, map);

    // Decrypt using the substitution map
    decrypt_substitution(ciphertext, plaintext, map);

    printf("Decrypted Text: %s\n", plaintext);

    return 0;
}

