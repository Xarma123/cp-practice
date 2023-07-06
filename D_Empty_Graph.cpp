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
        lol n, k;
        cin >> n >> k;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol s = 0, e = 1e9+1;
        while (s != e - 1)
        {
            lol m = (s + e) / 2ll;
            lol b[n];
            lol c = 0;
            for (lol i = 0; i < n; i++)
            {
                b[i] = a[i];
                if (2ll * b[i] < m)
                {
                    c++;
                    b[i] = 1e9;
                }
            }
            lol q = LONG_LONG_MAX;
            for (lol i = 1; i < n; i++)
            {
                if (b[i] < m && b[i - 1] < m)
                {
                    q = min(q, c + 2);
                }
                else if (b[i] < m || b[i - 1] < m)
                {
                    q = min(q, c + 1);
                }
                else
                {
                    q = min(q, c);
                }
            }
            if (q <= k)
            {
                s = m;
            }
            else
                e = m;
        }
        cout << s << endl;
    }

    return 0;
}