objects = cipher_test.o cipher.o

Vigenere : $(objects) cipher.h
	gcc -g -o Vigenere $(objects) -lncurses

cipher_test.o : cipher_test.c cipher.h 
	gcc -g -c cipher_test.c
cipher.o : cipher.c cipher.h
	gcc -g -c cipher.c

clean : 
	rm Vigenere $(objects)
