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
        lol a[n], b[n];
        lol s1 = 0, s2 = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            s1 += a[i];
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
            s2 += b[i];
        }
        sort(a, a + n);
        sort(b, b + n);
        cout << min(s1 + n * 1ll * b[0], s2 + n * 1ll * a[0]) << '\n';
    }
}