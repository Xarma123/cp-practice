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
        lol n;
        cin >> n;
        lol a[n];
        lol s = 0;
        lol ne = 0;
        lol mn = LONG_LONG_MAX;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] < 0)
                ne++;
            mn = min(mn, (long long)abs(a[i]));
            s += abs(a[i]);
        }
        if (ne % 2)
        {
            s -= mn;
            s -= mn;
        }
        cout << s << '\n';
    }

    return 0;
}