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
        lol n;
        cin >> n;
        lol a[n + 2];
        lol s = 0;
        map<lol, lol> f;
        for (lol i = 0; i < n + 2; i++)
        {
            cin >> a[i];
            f[a[i]]++;
            s += a[i];
        }
        lol i;
        for (i = 0; i < n + 2; i++)
        {
            if (--f[a[i]] == 0)
            {
                f.erase(a[i]);
            }
            lol v = s - a[i];
            lol ff = v - a[i];

            if (ff > 0 && f.count(ff))
            {
                for (lol j = 0; j < n + 2; j++)
                {
                    if (j == i)
                        continue;
                    if (a[j] == ff)
                    {
                        ff = LONG_LONG_MAX;
                        continue;
                    }
                    cout << a[j] << " ";
                }
                cout << '\n';
                break;
            }

            f[a[i]]++;
        }
        if (i >= n+2)
            cout << -1 << '\n';
    }
}