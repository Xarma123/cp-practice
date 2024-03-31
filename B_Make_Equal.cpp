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
        lol s = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            s += a[i];
        }
        s /= n;
        lol v = 0;
        bool ans = true;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] < s)
            {
                if (v >= s - a[i])
                {
                    v -= s - a[i];
                }
                else
                    ans = false;
            }
            else
                v += a[i] - s;
        }
        if (!ans)
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}
