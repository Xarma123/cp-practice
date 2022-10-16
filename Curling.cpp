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
    lol cae = 1;
    while (t--)
    {
        lol rs, rh;
        cin >> rs >> rh;
        lol n;
        cin >> n;
        vector<lol> a;
        lol cmp = (rs + rh) * 1ll * (rs + rh);
        for (lol i = 0; i < n; i++)
        {
            lol x, y;
            cin >> x >> y;
            lol d = x * 1ll * x + y * 1ll * y;
            if (d <= cmp)
            {
                a.push_back(d);
            }
        }
        lol m;
        cin >> m;
        vector<lol> b;
        for (lol i = 0; i < m; i++)
        {
            lol x, y;
            cin >> x >> y;
            lol d = x * 1ll * x + y * 1ll * y;
            if (d <= cmp)
            {
                b.push_back(d);
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if (a.size() == 0 || b.size() == 0)
        {
            cout << "Case #" << cae << ": " << a.size() << " " << b.size() << endl;
        }
        else if (a[0] > b[0])
        {
            lol i = lower_bound(b.begin(), b.end(), a[0]) - b.begin();
            cout << "Case #" << cae << ": " << 0 << " " << i << endl;
        }
        else
        {
            lol i = lower_bound(a.begin(), a.end(), b[0]) - a.begin();
            cout << "Case #" << cae << ": " << i << " " << 0 << endl;
        }
        cae++;
    }

    return 0;
}