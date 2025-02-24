/*! \file cipher_test.c */
#include <stdio.h>
#include <ncurses.h>
#include "cipher.h"

#define ENCRYPT
//define DECRYPT
//#define DEBUG

int main(void){
	char plainText[MAX_SENTENCE_LENGTH];
	char secretKey[MAX_KEY_LENGTH];
	char cipherText[MAX_SENTENCE_LENGTH]; 

	char title[] = "Vigenere Cipher Project";
	char encrypt_request[] = "Enter a sentence to encrypt - Maximum ";
	char decrypt_request[] = "Enter a sentence to decrypt - Maximum ";
	char secret_key_request[] = "Enter a secret key - Maximum ";

	initscr();

	addstr(title);

	move(2,0);

#ifdef ENCRYPT
	printw("%s %d characters:\n", encrypt_request, MAX_SENTENCE_LENGTH);
	refresh();
	getnstr(plainText, MAX_SENTENCE_LENGTH);
	
	printw("%s %d characters:\n" , secret_key_request, MAX_KEY_LENGTH);
	refresh();
	getnstr(secretKey, MAX_KEY_LENGTH);

	refresh();
	encrypt(plainText, cipherText, secretKey);  // encrypt

	printw("%s", cipherText);
#endif

#ifdef DECRYPT
	printw("%s %d characters:\n ", decrypt_request, MAX_SENTENCE_LENGTH);
	refresh();
	getnstr(cipherText, MAX_SENTENCE_LENGTH);

	printw("%s %d characters:\n" , secret_key_request, MAX_KEY_LENGTH);
	refresh();
	getnstr(secretKey, MAX_KEY_LENGTH);

	refresh();
	decrypt(cipherText, plainText, secretKey); // decrypt 

	printw("%s", plainText);
#endif

	getch();
	endwin(); 

	return 0;
}

