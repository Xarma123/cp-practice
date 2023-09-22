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
        lol n, x;
        cin >> n >> x;
        lol h[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> h[i];
        }
        lol s = 0, e = 3e9;
        while (s != e - 1)
        {
            lol m = (s + e) / 2;
            lol w = 0;
            for (lol i = 0; i < n; i++)
            {
                if (h[i] < m)
                    w += m - h[i];
            }
            if (w <= x)
                s = m;
            else
                e = m;
        }
        cout << s << '\n';
    }
}