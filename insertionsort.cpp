#include <iostream>
#include <conio.h>
using namespace std;

void insertionsort(lol a[], lol n)
{
   lol j , e;
    for (lol i = 1; i < n; i++)
    { 
      j=i-1;
     e=a[i];
        while(j>=0)
        {  
           
            if (a[j] > e)
            {
                swap(a[j], a[j + 1]);
            }
            j--;
        }
    }
}

int main()
{

    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        /* code */
    }

    insertionsort(a, n);
    for (lol i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    getch();
    return 0;
}