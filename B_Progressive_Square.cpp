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
        lol n, c, d;
        cin >> n >> c >> d;
        lol a[(n * 1ll * n)];
        multiset<lol> x;
        for (lol i = 0; i < n * 1ll * n; i++)
        {
            cin >> a[i];
            x.insert(a[i]);
        }
        lol sz = (n * 1ll * n) - 1;
        sort(a, a + (n * 1ll * n));
        lol v = a[sz];
        bool ans = true;
        for (lol i = 0; i < n; i++)
        {
            lol va = v;
            for (lol j = 0; j < n; j++)
            {
                
                if (x.find(va) != x.end())
                {
                    x.erase(x.find(va));
                }
                else
                    ans = false;
                va -= d;
            }
            v -= c;
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
