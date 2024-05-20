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
        if (a[0] != a[n - 1])
        {
            cout << 0 << '\n';
            continue;
        }
        lol i;
        for (i = 1; i < n; i++)
        {
            if (a[i] != a[0] && a[i - 1] != a[0])
            {
                cout << 0 << '\n';
                break;
            }
        }
        if (i != n)
        {
            continue;
        }
        lol c = 0;
        lol f = a[0];
        lol mn = LONG_LONG_MAX;
        for (lol i = 0; i < n; i++)
        {
            lol j = i + 1;
            while (j < n && a[j] == a[i])
                j++;
            if (a[i] == f)
            {
                c++;
                mn = min(mn, j - i);
            }
            i = j - 1;
        }
        if (c == 1)
        {
            cout << -1 << '\n';
        }
        else
            cout << mn << '\n';
    }

    return 0;
}
