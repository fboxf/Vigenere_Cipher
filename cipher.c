/*! \file cipher.c */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "cipher.h"

// prototypes
bool checkKey(char *strng);
char getSubstitution (char scrt_char, char plainOrCipher_char, bool de_Or_en);

// Function definitions

/** \brief Check if string contains only letters of the alphabet.
 *
 * Iterate through each character in a string and return false if a character is not
 * a letter from the alphabet.
 * @param[in] strng String to check. 
 * \returns bool True if only letters, false otherwise. */
bool checkKey(char *strng){
	int counter = 0; 

	while (strng[counter] != '\n'){
		if (!isalpha(strng[counter])){
			puts("Can't be used");
			return false;
		}
		counter++;
	}
	return true;

}

/** \brief Substitute one character with another. 
 *
 * This function is used for both encryption and decryption by way of a boolean value. Characters are converted to uppercase. For each character it performs the appropriate substitution.
 *
 * @param[in] scrt_char Secret-Key character.
 * @param[in] plainOrCipher_char Character from plaintext or ciphertext.
 * @param[in] encryptOrDecrypt Bool indicating whether to encrypt (true) or
 * decrypt (false).
 * */
char getSubstitution (char scrt_char, char plainOrCipher_char, bool Encrypt){
	static const char alphabet[ALPHABET_LENGTH] = {
		'A','B','C','D','E',
		'F','G','H','I','J',
		'K','L','M','N','O',
		'P','Q','R','S','T',
		'U','V','W','X','Y','Z'};
	
	static char Vigenere_Square[ALPHABET_LENGTH][ALPHABET_LENGTH] = {{' '}};


	if ((Vigenere_Square[0][0]) == ' '){ // call first time only
		for (size_t i = 0; i < ALPHABET_LENGTH; i++) {
			for (size_t j = 0; j < ALPHABET_LENGTH; j++){
				Vigenere_Square[i][j] = alphabet[(j + i) % ALPHABET_LENGTH];  
			}
		}
	}
	// convert to integer to traverse array
	// the ascii code for each is
	// a = 97, A = 65;
	int scrt_char_n;
	int plain_char_n;

	plainOrCipher_char = toupper(plainOrCipher_char);
	scrt_char = toupper(scrt_char);
	
	// give ascii numbers
	if (isupper(scrt_char)){scrt_char_n = scrt_char - 65;} // A = 0, ... Z = 25
	if (isupper(plainOrCipher_char)) {plain_char_n = plainOrCipher_char - 65;}

	// encrypt
	if((Encrypt)){
		return Vigenere_Square[scrt_char_n][plain_char_n];
	} 

	if(!(Encrypt)){

#ifdef DEBUG
		puts("Values supplied to function:");
		printf("scrt_char: %c\n", scrt_char);
		printf("plainOrCipher_char %c\n", plainOrCipher_char);
		puts("");
		puts("Converted to:");
		printf("scrt_char_n: %d\n", scrt_char_n);
		printf("plain_char_n: %d\n", plain_char_n);
#endif
		for (size_t i = 0; i < ALPHABET_LENGTH; i++){
			if(Vigenere_Square[scrt_char_n][i] == plainOrCipher_char){
				return Vigenere_Square[0][i];	
			}
		}
	}
}

/** Walks along plaintext string, repeatedly calling getSubstitution. 
 * @param[in] plainToEncrypt Plain text string.
 * @param[in] cipherTextArray Empty string of same length 
 * @param[in] scrt_strng Secret key string */
int encrypt (char *plainToEncrypt, char *cipherTextArray, char *scrt_strng){
	int p_counter = 0, s_counter = 0;

	if(!checkKey(scrt_strng)){
		return EXIT_FAILURE;
	}

	while (plainToEncrypt[p_counter] != '\0'){

		if (!isalpha(plainToEncrypt[p_counter])){
			cipherTextArray[p_counter] = plainToEncrypt[p_counter];
			p_counter++;
			continue;
		}

		cipherTextArray[p_counter] = getSubstitution(
				scrt_strng[s_counter], plainToEncrypt[p_counter], true);

		p_counter++; s_counter++;

		if (scrt_strng[s_counter] == '\n'){
			s_counter = 0;
		}
	}
	
	p_counter = 0;

	while (cipherTextArray[p_counter] != '\0'){
		printf("%c", cipherTextArray[p_counter]);
		p_counter++;
	}

	return EXIT_SUCCESS;
}

/** Decrypt ciphertext using a secret key 
 * @param[in] cipherToDecrypt Ciphertext
 * @param[in] plainTextArray Empty string of same length
 * @param[in] scrt_strng Secret key string */
int decrypt (char *cipherToDecrypt, char *plainTextArray, char *scrt_strng){
	int p_counter = 0, s_counter = 0;

	if(!checkKey(scrt_strng)){
		return EXIT_FAILURE;
	}

	while (cipherToDecrypt[p_counter] != '\0'){

		if (!isalpha(cipherToDecrypt[p_counter])){
			plainTextArray[p_counter] = cipherToDecrypt[p_counter]; // copy.. then move on
			p_counter++;
			continue;
		}

		plainTextArray[p_counter] = getSubstitution (
				scrt_strng[s_counter], cipherToDecrypt[p_counter], false);

		p_counter++; s_counter++;

		if (scrt_strng[s_counter] == '\n'){
			s_counter = 0;
		}
	}
	
	p_counter = 0;

	while (plainTextArray[p_counter] != '\0'){
		printf("%c", plainTextArray[p_counter]);
		p_counter++;
	}

	return EXIT_SUCCESS;
}

