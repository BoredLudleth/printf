all: compile link

compile: printf.asm
	nasm -g -f elf64 printf.asm -l printf.lst

link: printf.o
	ld -m elf_x86_64 printf.o -o printf

clean:
	rm *.o *.out *.lst