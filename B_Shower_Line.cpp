#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol g[5][5];
lol ans = LONG_LONG_MIN;
void solve(string a)
{
    if (a.size() == 5)
    {
        lol v = 0;
        for (lol j = 0; j < 5; j++)
        {
            for (lol i = j; i < 5; i += 2)
            {
                if (i + 1 < 5)
                {
                    lol a1 = a[i] - '1';
                    lol a2 = a[i + 1] - '1';
                    v += g[a1][a2];
                    v += g[a2][a1];
                }
            }
        }
    
        ans = max(ans, v);

        return;
    }
    for (lol i = 1; i <= 5; i++)
    {
        bool f = true;
        for (auto c : a)
        {
            if (c == char('0' + i))
                f = false;
        }
        if (f)
        {
            a.push_back(char('0' + i));
            solve(a);
            a.pop_back();
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (lol i = 0; i < 5; i++)
    {
        for (lol j = 0; j < 5; j++)
        {
            cin >> g[i][j];
        }
    }
    bool vis[5];
    solve("");
    cout << ans;

    return 0;
}