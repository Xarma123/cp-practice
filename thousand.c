#include <stdio.h>
#include <conio.h>
int main()
{
    prlolf("enter no of rows");
    lol n;
    scanf("%d", &n);
    lol arr[n][10011];
    for (lol row = 0; row < n; row++)
    {
        for (lol i = 0; i < 50 - row; i++)
        {
            prlolf(" ");
        }

        for (lol col = 0; col <= row; col++)
        {
            if (col == 0 || col == row)
            {
                prlolf("1 ");
                arr[row][col] = 1;
            }
            else
            {
                arr[row][col] = arr[row - 1][col] + arr[row - 1][col - 1];
                prlolf("%d ", arr[row][col]);
            }
        }
        prlolf("\n");
    }
    getch();
}