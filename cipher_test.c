/*! \file cipher_test.c */
#include <stdio.h>
#include "cipher.h"

//#define ENCRYPT
#define DECRYPT

//#define DEBUG

int main(void){
	char plainText[MAX_SENTENCE_LENGTH];
	char secretKey[MAX_KEY_LENGTH];
	char cipherText[MAX_SENTENCE_LENGTH]; 

	puts("Vigenere Cipher Project");
	puts("");

#ifdef ENCRYPT
	puts("Enter a sentence to encrypt: ");
	fgets(plainText, MAX_SENTENCE_LENGTH, stdin);
	puts("Enter a secret key of ONLY LETTERS (max 20): ");
	fgets(secretKey, MAX_KEY_LENGTH, stdin);

	encrypt(plainText, cipherText, secretKey);  // encrypt
#endif

#ifdef DECRYPT
	puts("Enter a sentence to decrypt: ");
	fgets(cipherText, MAX_SENTENCE_LENGTH, stdin);
	puts("Enter a secret key of ONLY LETTERS (max 20): ");
	fgets(secretKey, MAX_KEY_LENGTH, stdin);

	decrypt(cipherText, plainText, secretKey); // decrypt 

#endif

	return 0;
}

