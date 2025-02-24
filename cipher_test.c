/*! \file cipher_test.c */
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include "cipher.h"

//#define DEBUG

int main(void){
	char title[] = "Vigenere Cipher Project";
	char encrypt_request[] = "Enter a sentence to encrypt - Maximum ";
	char decrypt_request[] = "Enter a sentence to decrypt - Maximum ";
	char secret_key_request[] = "Enter a secret key - Maximum ";

	int ch;

	char plainText[MAX_SENTENCE_LENGTH];
	char secretKey[MAX_KEY_LENGTH];
	char cipherText[MAX_SENTENCE_LENGTH]; 

	initscr();

	attron(A_REVERSE);
	addstr(title);
	attroff(A_REVERSE);

	move(2,0);
	
	printw("Select an option:\n");
	printw("1. Encrypt\n");
	printw("2. Decrypt (q to quit) \n");

	while ( (ch = getch()) != 'q') {
		
		if (ch == '1'){
			memset(plainText, 0, strlen(plainText));
			memset(cipherText, 0, strlen(cipherText));
			memset(secretKey, 0, strlen(secretKey));

			printw("\nEncrypt\n");
			printw("%s %d characters:\n", encrypt_request, MAX_SENTENCE_LENGTH);
			refresh();

			getnstr(plainText, MAX_SENTENCE_LENGTH);
	
			printw("%s %d characters:\n" , secret_key_request, MAX_KEY_LENGTH);
			refresh();
			getnstr(secretKey, MAX_KEY_LENGTH);

			refresh();
			encrypt(plainText, cipherText, secretKey);  // encrypt

			printw("%s\n", cipherText);
			printw("(press any key to continue)");

			getch();

			clear();
			refresh();

			printw("Select an option:\n");
			printw("1. Encrypt\n");
			printw("2. Decrypt (q to quit)\n");
		}
		if (ch == '2'){
			memset(plainText, 0, strlen(plainText));
			memset(cipherText, 0, strlen(cipherText));
			memset(secretKey, 0, strlen(secretKey));

			printw("\nDecrypt\n");
			printw("%s %d characters:\n", decrypt_request, MAX_SENTENCE_LENGTH);
			refresh();
			getnstr(cipherText, MAX_SENTENCE_LENGTH);

			printw("%s %d characters:\n" , secret_key_request, MAX_KEY_LENGTH);
			refresh();
			getnstr(secretKey, MAX_KEY_LENGTH);

			refresh();
			decrypt(cipherText, plainText, secretKey); // decrypt 

			printw("%s\n", plainText);
			printw("(press any key to continue)");

			getch();
		
			clear();
			refresh();

			printw("Select an option:\n");
			printw("1. Encrypt\n");
			printw("2. Decrypt (q to quit) \n");
		}

		memset(plainText, 0, strlen(plainText));
		memset(cipherText, 0, strlen(cipherText));
		memset(secretKey, 0, strlen(secretKey));

	}

	endwin(); 

	return 0;
}

