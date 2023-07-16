#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        lol r;
        cin >> r;
        map<lol, pair<set<lol>, set<lol>>> mp;
        for (lol i = 0; i < r; i++)
        {

            lol t, d, c;
            cin >> t >> d >> c;
            if (d == 1)
            {
                mp[t].first.insert(c);
            }
            else
                mp[t].second.insert(c);
        }
        bool dp[n][m][r + 1];
        memset(dp, false, sizeof(dp));
        dp[0][0][0] = true;
        
    }
}