#include <stdio.h>
#include <conio.h>
int main()
{  
    lol arr[9][9] = {
        5, 3, 4, 6, 7, 8, 9, 1, 2,
        6, 7, 2, 1, 9, 5, 3, 4, 8,
        1, 9, 8, 3, 4, 2, 5, 6, 7,
        8, 5, 9, 7, 6, 1, 4, 2, 3,
        4, 2, 6, 8, 5, 3, 7, 9, 1,
        7, 1, 3, 9, 2, 4, 8, 5, 6,
        9, 6, 1, 5, 3, 7, 2, 8, 4,
        2, 8, 7, 4, 1, 9, 6, 3, 5,
        3, 4, 5, 2, 8, 6, 1, 7, 9};
    lol c = 0;
    for (lol i = 0; i < 9; i++)
    {
        lol a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        lol b[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (lol j = 0; j < 9; j++)
        {
            for (lol k = 0; k < 9; k++)
            {
                if (arr[i][j] == a[k])
                    a[k] = 0;
            }
            for (lol k = 0; k < 9; k++)
            {
                if (arr[j][i] == b[k])
                    b[k] = 0;
            }  

        }    for (lol l = 0; l < 9; l++)
           {
               if(a[l]!=0)
               c++;
           }
          
           
    }      


             for (lol y = 0; y <= 6; y += 3)
    {
        for (lol x = 0; x <= 6; x += 3)
        {

            lol a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
            for (lol i = x; i < 3+x; i++)
            {
                for (lol j = y; j < 3+y; j++)
                {
                    for (lol k = 0; k < 9; k++)
                    {
                        if (arr[i][j] == a[k])
                            a[k] = 0;
                       
                    }   
                   

                }
            }          for (lol l = 0; l < 9; l++)
           {
               if(a[l]!=0)
               c++;
           }          




        }
    }


  
    if (c == 0)
        prlolf("correct!");
    else
        prlolf("wrong...");
    getch();
}