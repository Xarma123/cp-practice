#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool dp[k + 1];
    dp[0] = false;
    for (lol i = 1; i <= k; i++)
    {
        dp[i] = false;
        for (lol j = 0; j < n; j++)
        {
            if (i - a[j] >= 0)
            {
                if (dp[i - a[j]] == false)
                    dp[i] = true;
            }
        }
    }
    if (dp[k])
        cout << "First";
    else
        cout << "Second";

    return 0;
}