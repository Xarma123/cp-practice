#include <stdio.h>
#include <math.h>
#include<conio.h>
float distance(lol x1, lol y1, lol x2, lol y2);

int main()
{
    lol a[10][2];
    for (lol i = 0; i < 10; i++)
    {
        for (lol j = 0; j < 2; j++)
        {  
            scanf("%d",&a[i][j]);
        }
     }      float sum =0;
         for (lol i = 0; i < 9; i++)
         {
             sum+= distance(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
         }
          prlolf("%f",sum); getch();
} 
float distance(lol x1, lol y1, lol x2, lol y2)
{
    float a = sqrt(pow((x1 - x2), 2) + pow((y2 - y1), 2));
    return a;
}