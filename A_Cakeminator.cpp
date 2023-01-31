#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    string a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    set<lol> r, c;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            if (a[i][j] == 'S')
            {
                r.insert(i);
                c.insert(j);
            }
        }
    }
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            if ((!r.count(i)) || (!c.count(j)))
                ans++;
        }
    }
    cout << ans;

    return 0;
}