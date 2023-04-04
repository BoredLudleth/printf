#include <stdio.h>
extern int _printf(const char* fmt, ...);

int main () {

    _printf ("Henlo, i'm little printf\nLet's test me\n");

    int x = 67;
    int y = -80;
    char a = 'v';
    char* slovo = "popa\0";
    printf("I love %d cappa %s\n", x, slovo);
    _printf("I love %x na %b%%%c \nI %s %x %d%%%c%b\n", 55, 8, '!', "love", 3802, 100, 33, 255);
    printf("I love %x cappa %s\n", y, slovo);
    //_printf ("Test#1:%% -percent\nTest#2:%b - bin\nTest#3:%c - char\nTest#4:%d -dec\nTest#5:%o - octo\nTest#5:%s - string\nTest#6:%x - hex\nTest#7:%x - hex2\nTest#8:%c - char\nTest#9:%d -dec\nTest#10:%o - octo\nTest#11:%x - hex\nTest#12:%s - string\n", 58, 'y', 58, 58, "It's String", 58, 0xbad, a, y, x, x, slovo); 
    
    return 0;
}