#include <bits/stdc++.h>
#define lol long long
using namespace std;

lol a[100005];
lol b[100005];
lol solve(lol st, lol e, lol p)
{
    lol ans = 0;
    if (st == e)
        return (a[e] ^ b[e]);
    for (lol i = p; i >= 0; i--)
    {
        lol o = 0, z = 0;
        for (lol j = st; j < e + 1; j++)
            if ((a[j] & (1ll << i)))
                o++;
        for (lol j = st; j < e + 1; j++)
            if (!(b[j] & (1ll << i)))
                z++;
        if (o == z)
        {
            ans |= (1ll << i);
            for (lol j = st; j < e + 1; j++)
            {
                a[j] &= ((1ll << (i + 1)) - 1ll);
                b[j] &= ((1ll << (i + 1)) - 1ll);
            }
            sort(a + st, a + e + 1);
            sort(b + st, b + e + 1, greater<lol>());
         
            ans |= (solve(st, st + o - 1, i - 1) & solve(st + o, e, i - 1));
            break;
        }
    }
    return ans;
}
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
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        cout << solve(0, n - 1, 31) << endl;
    }
    return 0;
}