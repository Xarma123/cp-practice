#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, s, k;
        cin >> n >> s >> k;
        lol mn1 = s;
        lol mn2 = s;
        set<lol> x;
        while (k--)
        {
            lol a;
            cin >> a;
            x.insert(a);
            while (x.count(mn1))
                mn1++;
            while (x.count(mn2))
                mn2--;
        }
        lol ans = LONG_LONG_MAX;
        if (mn1 <= n)
            ans = min(ans, mn1 - s);
        if (mn2 >= 1)
            ans = min(ans, s - mn2);
        cout << ans << endl;
    }

    return 0;
}