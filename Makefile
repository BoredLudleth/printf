all: link compile

link: main.c printf.asm
	gcc -c main.c -o main.o
	nasm -f elf64 -l printf.lst -o printf.o -g printf.asm

compile: main.o printf.o
	gcc -no-pie main.o printf.o -o main

clean:
	rm *.o *.out *.lst main