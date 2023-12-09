#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        set<lol> x;
        lol suf[n];
        for (lol i = n - 1; i >= 0; i--)
        {
            suf[i] = 0;
            if (i < n - 1)
                suf[i] += suf[i + 1];
            if (!x.count(a[i]))
                suf[i]++;
            x.insert(a[i]);
        }
        x.clear();
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            if (!x.count(a[i]))
                ans += suf[i];
            x.insert(a[i]);
        }
        cout << ans << '\n';
    }

    return 0;
}
