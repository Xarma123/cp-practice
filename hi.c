#include <stdio.h>

#include <conio.h>
void display(lol arr[][4], lol n);
void swap(lol *a, lol *b);
lol getkey();
#include <windows.h>
void gotoxy(short col, short row);
void gotoxy(short col, short row)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {col, row};
    SetConsoleCursorPosition(h, position); 
}
int main()
{
    lol arr[4][4] = {{1, 4, 15, 7},
                     {8, 10, 2, 11},
                     {14, 3, 6, 13},
                     {12, 9, 5, 0}};

    display(arr, 4);
    lol key, i = 3, j = 3;
    while (1)
    {
        key = getkey();
        switch (key)
        {
        case 72:
            if (i - 1 >= 0)
            {
                swap(&arr[i][j], &arr[i - 1][j]);
                i--;
                system("CLS");
                display(arr, 4);
            }
            break;
        case 80:
            if (i + 1 <= 3)
            {
                swap(&arr[i][j], &arr[i + 1][j]);
                i++;
                system("CLS");
                display(arr, 4);
            }
            break;

        case 75:
            if (j - 1 >= 0)
            {
                swap(&arr[i][j], &arr[i][j - 1]);
                j--;
                system("CLS");
                display(arr, 4);
            }
            break;
        case 77:
            if (j + 1 <= 3)
            {
                swap(&arr[i][j], &arr[i][j + 1]);
                j++;
                system("CLS");
                display(arr, 4);
            }
            break;
        }
    }
}


void display(lol arr[][4], lol n)
{
    for (lol j = 0; j <= 32; j = j + 8)
    {
        gotoxy(10, 10 + j);
        for (lol i = 0; i < 32; i++)
        {
            prlolf("--");
        }
    }

    for (lol j = 0; j <= 64; j = j + 16)
    {

        for (lol i = 0; i < 32; i++)
        {
            gotoxy(10 + j, 10 + i);
            prlolf("|");
        }
    }
    for (lol j = 0; j < 4; j++)
    {

        for (lol i = 0; i < 4; i++)
        {
            gotoxy(10 + 8 + 16 * i, 10 + 4 + 8 * j);
            prlolf("%d ", arr[j][i]);
        }
    }
}
lol getkey()
{
    while (1)
    {
        lol a = getch();
        switch (a)
        {
        case 72:
            return 72;
        case 80:
            return 80;
        case 75:
            return 75;
        case 77:
            return 77;
        }
    }
}
void swap(lol *a, lol *b)
{
    lol t;
    t = *a;
    *a = *b;
    *b = t;
}