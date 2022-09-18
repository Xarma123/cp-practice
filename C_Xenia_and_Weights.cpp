#include <bits/stdc++.h>
#define lol long long
using namespace std;
string s;
lol m;
vector<lol> ans(1001);
bool dfs(lol b, lol p, lol n)
{
    if (n == m)
        return true;
    for (lol i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '1' && p != i + 1)
        {
            if (n % 2 == 0)
            {
                if (b + i + 1 > 0)
                {
                    ans[n] = i + 1;
                    if (dfs(b + i + 1, i + 1, n + 1))
                        return true;
                }
            }
            else
            {
                if (b - i - 1 < 0)
                {
                    ans[n] = i + 1;
                    if (dfs(b - i - 1, i + 1, n + 1))
                        return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    cin >> m;
    if (dfs(0, 0, 0))
    {
        cout << "YES" << endl;
        for (lol i = 0; i < m; i++)
        {
            cout << ans[i] << " ";
        }
    }
    else
        cout << "NO";
    return 0;
}