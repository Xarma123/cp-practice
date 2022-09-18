#include <iostream>
using namespace std;
int main()
{
    lol r, c;
    cin >> r >> c;
    lol a[r][c];
    for (lol i = 0; i < r; i++)
    {
        for (lol j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }    
         for (lol i = 0; i < r; i++)
         {
             for (lol j = 0; j < c/2; j++)
             {   swap(a[i][j],a[i][r-1-j]);
                  
             }
             
         }
         



    for (lol i = 0; i < r; i++)
    {        
        for (lol j = i; j < c; j++)
        {     
            lol t = a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=t;
        }
    }   
   
      

    for (lol i = 0; i < r; i++)
    {
         for (lol j = 0; j <c ; j++)
         {
              cout<<a[i][j]<<" ";
         }
          cout<<endl;
    }
    
}