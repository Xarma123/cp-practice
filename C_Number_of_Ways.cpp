#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    lol s = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    if (s % 3 != 0)
        cout << 0;
    else
    {
        lol p[n];
        s /= 3;
        lol v = 0;
        for (lol i = n - 1; i >= 0; i--)
        {
            p[i] = 0;
            if (i + 1 < n)
                p[i] = p[i + 1];
            v += a[i];
            if (v == s)
                p[i]++;
        }
        v = 0;
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            v += a[i];
            if (v == s)
            {
                if (i + 2 < n)
                    ans += p[i + 2];
            }
        }
        cout << ans << endl;
    }

    return 0;
}