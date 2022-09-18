#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
void f(lol a[], lol x)
{
   if(x==1)
   return ;
  
    swap(a[x-1],a[x-2]);
    f(a,x-1);
}
int main()
{
    lol n;
    cin >> n;
    lol a[n] = {0};
    for (lol i = 0; i < n; i++)
    {
     a[i]=i+1;
    }
    f(a, n );
    for (lol i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}