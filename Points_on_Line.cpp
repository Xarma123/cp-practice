#include <bits/stdc++.h>
#define lol long long
using namespace std;

int main()
{
    lol n, d;
    cin >> n >> d;

    lol a[n];
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol j = 0;
    for (lol i = 0; i < n; i++)
    {
        while (a[j] - a[i] <= d)
        {
            j++;
            if (j == n)
            {
               
                break;
            } 
        }
          j--; 
        if (j == n - 1)
        {
            ans += (j - i + 1) * (j - i) * (j - i - 1) / 6;
            break;
        }
        else
            ans += (j - i) * (j - i - 1) / 2;
    }

    cout << ans;
    

    return 0;
}