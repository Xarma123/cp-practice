#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
void gotoxy(short col, short row);

int main()
{

    char month[10];
    prlolf("enter month(in alphabets please)\n ");
    gets(month);
    strlwr(month);
    lol year;
    prlolf("enter year\n ");
    scanf("%d", &year);
    system("cls");
    lol days;
    days = year * 365;
    char months[100] =
        " january februarymarchaprilmayjunejulyaugustseptemberoctobernovemberdecember";

    char *x = strstr(months, month);
    lol p = x - months;
    lol count =0;
    switch (p)
    {
    case 1:
        days = days; //jan
        count =31;
        break;
    case 9:
        days += 31; //feb
        count =28;
        break;
    case 17:
        days += 59; //march
        count =31;
        break;
    case 22:
        days += 90; //april
        count =30;
        break;
    case 27:
        days += 120; //may
        count =31;
        break;
    case 30:
        days += 151; //june
        count =30;
        break;
    case 34:
        days += 181; //july
        count =31;
        break;
    case 38:
        days = +212; //august
        count =31;
        break;
    case 44:
        days += 243; //september
        count =30;
        break;
    case 53:
        days += 273; //october
        count =31;
        break;
    case 60:
        days += 304; //november
        count =30;
        break;
    case 68:
        days += 334; //december
        count =31;
        break;

    default:
        prlolf("chutiye spelling seekh le ");goto f;
        break;
    }
    gotoxy(22, 1);
    strupr(month);
    prlolf("%s %d", month, year);  

    char *a[] = {"Mon", "Tues", "Wed",
                 "Thu", "Fri", "Sat","Sun"};
    for (lol i = 0; i < 7; i++)
    {
        gotoxy((2 + 6 * i), 2);
        prlolf(" %s ", a[i]);
    }   lol l = days%7; lol _a=1;
    
        for (lol j = 0; ; j++)
        {
            for (lol i =l ; (i < 7)&&(_a<=count); i++)
            {     gotoxy(2+i*6,3+j);
                   prlolf(" %d ",_a); 
                    _a++;
                 
                
            }  
             l=0;  
             if(_a>count)
             break;

            
        }
        

      f:

    getch();
}
void gotoxy(short col, short row)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {col, row};
    SetConsoleCursorPosition(h, position);
}