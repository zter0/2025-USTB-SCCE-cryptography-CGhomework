#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 256
#define INPUT_FILE "encrypt.txt"
#define OUTPUT_FILE "output.txt"

void encrypt_file(const char *key) {
    FILE *fin = fopen(INPUT_FILE, "r");
    FILE *fout = fopen(OUTPUT_FILE, "w");
    
    int key_len = strlen(key);
    int key_index = 0;
    char ch;
    
    while ((ch = fgetc(fin)) != EOF) {
        if (isupper(ch)) {
            char encrypted_char = ((ch - 'A') + (key[key_index] - 'A')) % 26 + 'A';
            fputc(encrypted_char, fout);
            key_index = (key_index + 1) % key_len;
        } else {
            key_index = (key_index + 1) % key_len;
            fputc(ch, fout);
        }
    }
    
    fclose(fin);
    fclose(fout);
}

int main() {
    char key[MAX_KEY_LEN + 1];
    
    if (scanf("%256s", key) != 1) {
        fprintf(stderr, "Invalid input.\n");
        return EXIT_FAILURE;
    }
    
    encrypt_file(key);
    
    return EXIT_SUCCESS;
}
