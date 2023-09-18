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
        lol n, m;
        cin >> n >> m;
        lol p[m];
        for (lol i = 0; i < m; i++)
        {
            cin >> p[i];
        }
        lol ans[n];
        memset(ans, -1, sizeof(ans));
        set<lol> x;
        for (lol i = 0; i < m; i++)
        {
            if (!x.count(p[i]))
            {
                ans[n - 1 - x.size()] = i + 1;
                x.insert(p[i]);
            }
            if (x.size() >= n)
                break;
        }
        for (lol i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
}