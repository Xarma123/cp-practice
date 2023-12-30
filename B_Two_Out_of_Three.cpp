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
        lol n;
        cin >> n;
        lol a[n];
        map<lol, lol> f;
        lol v = -1, v2 = -1;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            f[a[i]]++;
            if (f[a[i]] >= 2)
            {
                if (v == -1)
                    v = a[i];
                else if (v != a[i])
                    v2 = a[i];
            }
        }
        if (v == -1 || v2 == -1)
            cout << -1 << '\n';
        else
        {
            lol c = 1;
            lol c2 = 2;
            for (lol i = 0; i < n; i++)
            {
                if (a[i] != v && a[i] != v2)
                    cout << 3 << " ";
                else if (a[i] == v)
                    cout << min((c++), 2ll) << ' ';
                else if (a[i] == v2)
                {
                    cout << min((c2++), 3ll) << " ";
                }
            }
            cout << '\n';
        }
    }

    return 0;
}
