#include <stdio.h>
#include <string.h>
#include <math.h>
#include <conio.h>
lol atio(char *q);
int main()
{
    char str[25];
    gets(str);
    lol i;
    i = atio(str);
    prlolf("%d", i);
    getch();
}
lol atio(char *q)
{
    lol x = 0;
    lol n = strlen(q) - 1;

    while (n >= 0)
    {
        lol d = *(q + (strlen(q) - 1) - n);
        switch (d)
        {
        case 48:
            x = x + 0 * pow(10, n);
            break;

        case 49:
            x = x + 1 * pow(10, n);
            break;
        case 50:
            x = x + 2 * pow(10, n);
            break;
        case 51:
            x = x + 3 * pow(10, n);
            break;
        case 52:
            x = x + 4 * pow(10, n);
            break;
        case 53:
            x = x + 5 * pow(10, n);
            break;
        case 54:
            x = x + 6 * pow(10, n);
            break;
        case 55:
            x = x + 7 * pow(10, n);
            break;
        case 56:
            x = x + 8 * pow(10, n);
            break;
        case 57:
            x = x + 9 * pow(10, n);
            break;
        }

        n--;
    }

    return x;
}