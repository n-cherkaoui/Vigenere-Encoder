/*=============================================================================
 | Purpose - Encrypting a plaintext file using the Vigenere cipher
 |
 | Author:     Nawfal Cherkaoui Elmalki
 | Language:   C
 |
 | To Compile: gcc pa01.c -o ./pa01
 |
 |
 | To Execute: c -> ./pa01 kX.txt pX.txt
 |                  where kX.txt is the keytext file
 |                  and pX.txt is plaintext file
 |
 |       Note: All input files are simple 8 bit ASCII input
 |
 +=============================================================================*/

// Pre-processor directives
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 512

// Function declarations
int *Read(FILE *textFile, int *outputSize);
int *Plaintext_Filler(int *plaintext, int size);
int *Encrypt(int *plaintext, int *key, int keySize);
void Display(int *text, int textSize);

// driver function
int main(int argc, char **argv) {

  // Takes in CLI arguments and initializes variables
  FILE *keyFile = fopen(argv[1], "r"), *plaintextFile = fopen(argv[2], "r");
  int *key = NULL, *plaintext = NULL, *ciphertext = NULL;
  int keySize = 0, plaintextSize = 0;

  if (keyFile == NULL || plaintextFile == NULL) {
    printf("Error opening file");
    exit(1);
  }

  // Reads and displays the contents of the key file
  printf("\n\nVigenere Key:\n\n");
  key = Read(keyFile, &keySize);
  Display(key, keySize);

  // Reads and displays the contents of the Plaintext file
  printf("\n\nPlaintext:\n\n");
  plaintext = Read(plaintextFile, &plaintextSize);
  Plaintext_Filler(plaintext, plaintextSize);
  plaintextSize = MAX;
  Display(plaintext, plaintextSize);

  // Displays the encrypted cipher text
  printf("\n\nCiphertext:\n\n");
  ciphertext = Encrypt(plaintext, key, keySize);
  Display(ciphertext, MAX);

  return 0;
}

// Takes in a text file and counts the number of alphabet characters
int *Read(FILE *textFile, int *outputSize) {
  char currentChar;
  int *temp = malloc(512 * sizeof(int));
  int i = 0;

  while (!feof(textFile)) {

    currentChar = fgetc(textFile);

    if (isalpha(currentChar)) {
      temp[i] = tolower(currentChar) - 97;
      *outputSize += 1;
      i++;
    }
  }

  return temp;
}

// Pads plaintext with X until the character count is evenly divisible by the
// key's character count
int *Plaintext_Filler(int *plaintext, int size) {
  int X = 23;
  
  for (int i = size; i < MAX; i++) {
    plaintext[i] = X;
  }
  //return plaintext;
}

// Encrypts the plaintext
int *Encrypt(int *plaintext, int *key, int keySize) {
  int *temp = malloc(MAX * sizeof(int));

  for (int i = 0; i < MAX; i++) {
    temp[i] = (plaintext[i] + key[i % keySize]) % 26;
  }

  return temp;
}

// Displays the ASCII form of any int array passed in
void Display(int *text, int textSize) {
  
  for (int i = 1; i < textSize+1; i++) {
    printf("%c", text[i-1] + 97);
    
    if (i % 80 == 0)
      printf("\n");
  }
  
  printf("\n");
}
