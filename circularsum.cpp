#include <iostream>
#include <climits>
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[2 * n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (lol i = n; i < 2 * n; i++)
    {
        a[i] = a[i - n];
    }
    lol max = INT_MIN;
    lol sum = 0, s = 0, e = 0;
    for (lol i = 0; i < 2 * n; i++)
    {
        sum += a[i];
        e = i;
        if ((e - s + 1) > n)
        {
            sum = a[i];
        }  
        if (sum > max)
        {
            max = sum;
        }
        if (sum < 0)
        {
            s = i + 1;
            sum = 0;
        }
    }  cout<<max;
}