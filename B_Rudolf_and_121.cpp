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
        bool f = true;
        for (lol i = 0; i + 2 < n; i++)
        {
            if (a[i] < 0)
            {
                f = false;
                break;
            }
            a[i + 1] -= 2ll * a[i];
            a[i + 2] -= a[i];
            a[i] = 0;
        }
        for (lol i = 0; i < n; i++)
        {
            if (a[i] != 0)
                f = false;
        }

        if (f)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
