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
        lol a[n];
        lol p1 = 0;
        lol c = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            c += a[i];
            p1 = max(p1, c);
        }
        lol m;
        cin >> m;
        lol b[m];
        lol p2 = 0;
        c = 0;
        for (lol i = 0; i < m; i++)
        {
            cin >> b[i];
            c += b[i];
            p2 = max(p2, c);
        }
        cout << p1 + p2 << '\n';
    }
}