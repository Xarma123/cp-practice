#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long lol n;
    cin >> n;
    long long lol a[n];
    for (long long lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long lol m;
    cin >> m;
    long long lol t, a1 = 0, a2 = 0;
    for (long long lol i = 0; i < m; i++)
    {
        cin >> t; 
        long long lol s=0,e=n-1;  
        for (long long lol j = 0; j < n; j++)
        {
            if (a[j] == t)
            {
                a1 += j + 1;
                a2 += n - j;
                break;
            }
        }
    }

    cout << a1 << " " << a2;
}