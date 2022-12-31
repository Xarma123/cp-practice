#include <bits/stdc++.h>
#define lol long long
using namespace std;
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
        multiset<lol> x;
        for (lol i = 1; i <= n; i++)
        {
            lol v;
            cin >> v;
            x.insert(v);
        }
        while (m--)
        {
            lol v;
            cin >> v;
            x.erase(x.begin());
            x.insert(v);
        }
        lol ans = 0;
        for (auto e : x)
            ans += e;
        cout << ans << endl;
    }

    return 0;
}