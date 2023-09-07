#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        lol n = a.size();
        bool dp[n + 1];
        dp[0] = true;
        for (lol i = 0; i < n; i++)
        {
            dp[i + 1] = false;
            if (a[i] == b[i])
            {

                for (lol k = i; k >= 0; k--)
                {
                    if (a[k] == b[k] && a[k] == a[i])
                    {
                        dp[i + 1] |= dp[k];
                    }
                }
            }
        }
        if (dp[n])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}