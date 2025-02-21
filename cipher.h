/*! \file cipher.h */
#ifndef CIPHER_H
#define CIPHER_H

#define MAX_SENTENCE_LENGTH 100 /*!< \def Maximum length of sentence to encrypt or decrypt */
#define MAX_KEY_LENGTH 20 /*!< \def Maximum secret-key length */
#define ALPHABET_LENGTH 26 

int encrypt (char *plainToEncrypt, char *cipherTextArray, char *scrt_strng);
int decrypt (char *cipherToDecrypt, char *plainTextArray, char *scrt_string);

#endif
