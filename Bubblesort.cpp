#include <iostream>
#include <conio.h>
using namespace std;
void Bubblesort(lol a[], lol n)
{  for (lol i = n-1; i >0;--i)
{         
   for (lol j = 0; j < i; j++)
   {
       if (a[j]>a[j+1])
       {
           swap(a[j],a[j+1]);
       }
       
   }
   
}

}

int main()
{

    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n ; i++)
    {
        cin >> a[i];
    }

    Bubblesort(a, n);
    for (lol i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    getch();
    return 0;
}