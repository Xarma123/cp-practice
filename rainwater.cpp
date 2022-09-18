#include <iostream>
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol water = 0;
    lol max = a[0];
    lol index = 0;
    for (lol i = 1; i < n; i++)
    {  if(a[i]>max)
        {
            max = a[i];
            index = i;
        }
    } 
      


}