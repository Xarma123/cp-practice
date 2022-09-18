#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        map<lol, lol> mp;
        lol p = 0;
        lol dp[n];
        for (lol i = 0; i < n; i++)
        {
            if (i > 0)
                dp[i] = dp[i - 1] + mp[a[i]];
            else
                dp[i] = 0;

            mp[a[i]] += (i + 1);
            p+=dp[i];
        }

        cout << p << endl;
    }

    return 0;
}