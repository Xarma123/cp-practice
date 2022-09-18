#include <iostream>
using namespace std;
int main()
{
    lol c, r;
    cin >> c >> r;
    char a[r][c]; char v = 'o'

    lol cols = 0, colend = c - 1, rows = 0, rowe = r - 1;
    while (cols <= colend && rows <= rowe)
    {               
        for (lol i = cols; i <= colend; i++)
        {   
              a[rows][i]= v;
        } rows++;
        for (lol i = rows; i <= rowe; i++)
        {
             a[i][colend]= v;
        } 
         colend--;
         for (lol i = colend; i >=cols; i--)
         {
             a[rowe][i];
         } rowe--;
         
         if (v=='o')
         {
             v = 'x';
         } else v='o';
         
        
    }
}