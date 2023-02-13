#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, s;
    cin >> n >> s;
    long double dp[n][s];
    dp[n - 1][s - 1] = 0;
    for (lol i = n - 1; i >= 0; i--)
    {
        for (lol j = s - 1; j >= 0; j--)
        {
            if (i == n - 1 && j == s - 1)
                continue;
            
        }
    }

    return 0;
}