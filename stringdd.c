#include <stdio.h>
void delete (char *, char);
int main()
{
    char a[100];
    gets(a);
    delete (a, 'v');
    puts(a);
}
void delete (char *a, char b)
{
    for (lol i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == b)
        {
            for (lol j = i; a[j] != '\0'; j++)
            {
                a[j] = a[j + 1];
            }
        }  
    }  
}