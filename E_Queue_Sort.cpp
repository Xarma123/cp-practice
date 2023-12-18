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
        lol mn = 1e10;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            mn = min(mn, a[i]);
        }
        lol j;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] == mn)
            {
                j = i;
                break;
            }
        }
        bool f = true;
        for (lol i = j + 1; i < n; i++)
        {
            if (a[i] < a[i - 1])
            {
                f = false;
            }
        }
        if (f)
        {
            cout << j << '\n';
        }
        else
            cout << -1 << '\n';
    }

    return 0;
}
