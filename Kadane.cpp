#include <iostream>
#include <conio.h>
#include <climits>
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
    lol sum = 0;
    lol max = INT_MIN;
    for (lol i = 0; i < n; i++)
    {  
        sum = sum + a[i];
       
        if (sum > max)
        {
            max = sum;
        } 
          if (sum < 0)
        {
            sum = 0;
        }
    }
    cout<<max;
    getch();
    return 0;
}