#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol m, x;
        cin >> m >> x;
        lol c[m];
        for (lol i = 0; i < m; i++)
        {
            cin >> c[i];
        }
        multiset<lol> s;
        lol ans = 0;
        lol av = x;
        for (lol i = 1; i < m; i++)
        {
            s.insert(c[i]);
            if (av >= c[i])
            {
                ans++;
            }
            else
            {
                av += (*s.rbegin());
                s.erase(s.find((*s.rbegin())));
            }
            av -= c[i];
            av += x;
        }
        cout << ans << '\n';
    }

    return 0;
}
