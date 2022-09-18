#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{

    char n[81];
    scanf("%[^\n]s", n);
    prlolf("%s\n", n);
    char vowels[10] = "the";
    char ab[] = {'\0'};
    char *p;
    char *a = strstr(n, vowels);
    while (a)
    {    strcpy(p,(a+strlen(vowels)));
         strcpy(a,ab);
         strcat(n,p);

        a = strstr(n, vowels);
    }
    prlolf("%s\n", n);
    getch();
}