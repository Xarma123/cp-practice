#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, q;
    cin >> n >> q;
    lol a[n];
    lol c[51];
    for (lol i = 0; i < 51; i++)
    {
        c[i] = LONG_LONG_MAX;
    }

    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        c[a[i]] = min(c[a[i]], i + 1);
    }
    while (q--)
    {
        lol t;
        cin >> t;
        cout << c[t] << " ";
        for (lol i = 0; i < 51; i++)
        {
            if (c[i] != LONG_LONG_MAX)
            {
                if (i != t && c[i] < c[t])
                    c[i]++;
            }
        }
        c[t] = 1;
    }

    return 0;
}