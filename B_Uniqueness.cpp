#include <bits/stdc++.h>
#define lol long long
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
    lol ans = n - 1;
    map<lol, lol> mp;
    for (lol i = 0; i < n; i++)
    {
        lol j;
        for (j = 0; j < i; j++)
        {
            mp[a[j]]++;
            if (mp[a[j]] > 1)
                break;
        }
        if (j != i)
        {
            mp.clear();
           break;
        }

        for (j = n - 1; j >= i; j--)
        {
            mp[a[j]]++;
            if (mp[a[j]] > 1)
                break;
        }
        ans = min(ans, j - i+1);
        if (ans == 0)
            break; 
        mp.clear();
    }
    cout << ans;

    return 0;
}