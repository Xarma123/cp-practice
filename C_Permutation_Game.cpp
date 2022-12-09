#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    bool dp[n];
    memset(dp, false, sizeof(dp));
    lol v[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        v[a[i] - 1] = i;
    }
    for (lol i = n - 1; i >= 0; i--)
    {
        lol ii = v[i];
        for (lol j = ii; j < n; j += i + 1)
        {
            if (a[j] > a[ii] && dp[j] == false)
                dp[ii] = true;
        }
        for (lol j = ii; j >= 0; j -= i + 1)
        {
            if (a[j] > a[ii] && dp[j] == false)
                dp[ii] = true;
        }
    }
    for (lol i = 0; i < n; i++)
    {
        if (dp[i])
            cout << "A";
        else
            cout << "B";
    }

    return 0;
}