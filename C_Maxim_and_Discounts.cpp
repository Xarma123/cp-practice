#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol m;
    cin >> m;
    lol q[m];
    for (lol i = 0; i < m; i++)
    {
        cin >> q[i];
    }
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    sort(q, q + m);
    lol ans = 0;
    lol i = n - 1;
    while (i >= 0)
    {
        lol c = q[0];
        while (c-- && i >= 0)
        {
            ans += a[i];
            i--;
        }
        i -= 2;
    }
    cout << ans;

    return 0;
}