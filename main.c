// #include <stdio.h>
extern int _printf(const char* fmt, ...);

int main () {

    _printf ("Ultra Mega Failed printf\n");

    _printf ("%% -percent\n%b - bin\n%c - char\n%d -dec\n%o - octo\n%s - string\n%x - hex\n", 58, 'y', 58, 58, "It's String", 58, 58);
    _printf ("\n\n");

    int x = 67;
    int y = -80;
    char a = 'v';
    char slovo[10] = "pop\0";
    slovo[6] = 0;

    _printf ("\n%c - char\n%d -dec\n%o - octo\n%x - hex\n%s - string\n", a, y, x, x, slovo);
    _printf ("%x", 8);

    return 0;
}