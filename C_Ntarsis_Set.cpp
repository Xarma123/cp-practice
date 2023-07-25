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
        lol n, k;
        cin >> n >> k;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol s = 0, e = 1e18;
        while (s != e - 1)
        {
            lol m = (s + e) / 2;
            if (m == 0)
            {
                s = m;
                continue;
            }
            lol i = n - 1;
            lol cur = m;
            for (lol q = 0; q < k; q++)
            {
                while (i >= 0 && a[i] > cur)
                    i--;
                if (i >= 0)
                {
                    cur -= (i + 1);
                }
            }
            if (cur <= 0)
                s = m;
            else
                e = m;
        }
        cout << e << '\n';
    }
}