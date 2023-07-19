#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol m, s;
        cin >> m >> s;
        lol b[m];
        for (lol i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        sort(b, b + m);
        lol l = 0;
        lol ex = 0;
        for (lol i = 0; i < m; i++)
        {
            // l+1 to b[i]-1
            ex += ((b[i] - 1) * 1ll * (b[i]) / 2ll) - (l * 1ll * (l + 1) / 2ll);
            l = b[i];
        }

        s -= ex;
        lol v = b[m - 1] + 1;
        while (s > 0)
        {
            s -= v;
            v++;
        }
        if (s == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}