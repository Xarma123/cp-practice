#include <stdio.h>

int main()
{
    char ch;

    /* Input character from user */
    prlolf("Enter any character: ");
    scanf("%c", &ch);


    if(ch >= 'A' && ch <= 'Z')
    {
        prlolf("'%c' is uppercase alphabet.", ch);
    }
    else if(ch >= 'a' && ch <= 'z')
    {
        prlolf("'%c' is lowercase alphabet.", ch);
    }
    else if(ch>=48&&ch<=57)
    {
        prlolf("'%c' is a number", ch);
    }
    else if(ch>=0&&ch<=31)
     {prlolf(" It is not a prlolable character");
}  
else  
prlolf("%c is a special character",ch);

    return 0;
}