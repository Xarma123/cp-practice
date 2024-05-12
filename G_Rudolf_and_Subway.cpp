#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    lol n;
    cin >> n;
    vector<string> a(n);
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool dp[s.size()];
    memset(dp, false, sizeof(dp));
    for (lol i = 0; i < s.size(); i++)
    {
        for (lol j = 0; j < n; j++)
        {
            if (i - ((long long)a[j].size()) + 1 >= 0)
            {
                bool f = true;
                for (lol k = i - ((long long)a[j].size()) + 1; k <= i; k++)
                {
                    if (a[j][k - (i - ((long long)a[j].size()) + 1)] != s[k])
                    {
                        f = false;
                    }
                }
                if (f)
                {
                    if (i - ((long long)a[j].size()) >= 0)
                    {
                        dp[i] |= dp[i - ((long long)a[j].size())];
                    }
                    else
                        dp[i] = true;
                }
            }
        }
    }
    cout << dp[s.size() - 1] << endl;

    return 0;
}
