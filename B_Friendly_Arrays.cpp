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
        lol n, m;
        cin >> n >> m;
        lol a[n];
        lol a1 = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            a1 ^= a[i];
        }
        lol s = 0;
        lol b[m];
        for (lol i = 0; i < m; i++)
        {
            cin >> b[i];
            s |= b[i];
        }
        lol a2 = 0;
        for (lol i = 0; i < n; i++)
        {
            a[i] |= s;
            a2 ^= a[i];
        }
        cout << min(a2, a1) << " " << max(a2, a1) << '\n';
    }
}