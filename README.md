# Vigenere Cipher How to Program (Ninth Edition) - Global Edition - Deitel,P and Deitel, H
# Chapter 8: Characters and Strings Project 8.41 Programming Project: Pqyoaf Nylfomigrob Qwbbfmh Mndogvk: Rboqlrut yua Boklnxhmywex

## Programming Tools 🧰
- VIM
- GCC (compiled using: gcc -std=c18 -Wall cipher.c cipher_test.c -o cipher_test)

## Brief
This project allowed me to learn 👨‍🏫 about creating a secret key 🔐 called the Vigenere cipher. It's a development on the well-known Caesar cipher.Using the Caesar cipher each letter is shifted (encrypted) according to:

> f (p) = (p + x)mod26

x is the amount of shifting through the alphabet to encode the original text (the plaintext) into a hidden message (the ciphertext). For example if i x = 1 then

> a = b,
> b = c,
> ...,
> z=a

Decryption occurs through:

> f(to the power of -1)(p) = (p − k) mod 26

This may have been good on the battlefield, or as a child sharing the location of your toy cars🚗, but it is fairly (very?!) easy to break.

The Vigenere cipher was created to make this a bit more difficult by creating a two-dimensional matrix of letters

[Vigenere Cipher](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher)

## Compilation
Using Gcc, download the files into a folder and type the following:

> gcc -std=c18 -Wall cipher.c cipher_test.c -o cipher_test -lncurses

In cipher_test.c there are two macro definitions ENCRYPT and DECRYPT. _Simply comment out the appropriate choice and recompile_. Run using executable ./cipher_test

ALternatively, run the enclosed Makefile:

> make 
