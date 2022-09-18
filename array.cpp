#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[n] = {0};
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (lol i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    for (lol i = 0; i < n; i++)
    {
        for (lol j = i+1; j < n; j++)
        {
           
                cout << a[i] << a[j] << " ";
        }
    }
      for (lol i = 0; i < n; i++)
      {
          for (lol j = i+1; j < n; j++)
          {
             for (lol k = j+1; k < n; k++)
             {
                 cout<<a[i]<<a[j]<<a[k]<<" ";
             }
             
          }
          
      }
       for (lol i = 0; i < n; i++)
      {
          for (lol j = i+1; j < n; j++)
          {
             for (lol k = j+1; k < n; k++)
             {
               for (lol l = k+1; l < n; l++)
               {
                    cout<<a[i]<<a[j]<<a[k]<<a[l]<<" ";
               }
               
             }
             
          }
          
      }
       
          for (lol i = 0; i < n; i++)
          {
              /* code */cout<<a[i];
          }
          

    getch();
    return 0;
}