#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

void generateCipherSequence(char* keyword, char* cipher) {
    int seen[ALPHABET_SIZE] = {0};
    int index = 0;
    
    
    for (int i = 0; keyword[i] != '\0'; i++) {
        char ch = toupper(keyword[i]);
        if (!seen[ch - 'A']) {
            cipher[index++] = ch;
            seen[ch - 'A'] = 1;
        }
    }

    
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (!seen[ch - 'A']) {
            cipher[index++] = ch;
        }
    }
    cipher[index] = '\0'; 
}

void encrypt(char* plaintext, char* ciphertext, char* cipher) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char ch = toupper(plaintext[i]);
        if (isalpha(ch)) {
            ciphertext[i] = cipher[ch - 'A'];
        } else {
            ciphertext[i] = ch; 
        }
    }
    ciphertext[strlen(plaintext)] = '\0'; 
}

int main() {
    char keyword[] = "CIPHER";
    char plaintext[] = "HELLO WORLD";
    char cipher[ALPHABET_SIZE + 1];
    char ciphertext[100];

    generateCipherSequence(keyword, cipher);
    encrypt(plaintext, ciphertext, cipher);

    printf("Keyword: %s\n", keyword);
    printf("Cipher Sequence: %s\n", cipher);
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
