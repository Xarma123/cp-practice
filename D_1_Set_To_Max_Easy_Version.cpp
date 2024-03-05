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
        lol b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        bool ans = true;
        for (lol i = 0; i < n; i++)
        {

            bool f = false;
            lol mn = b[i];
            lol mx = a[i];
            for (lol j = i; j >= 0; j--)
            {
                mx = max(mx, a[j]);
                mn = min(mn, b[j]);
                if (a[j] == b[i])
                {
                    if (mx == mn && mx == b[i])
                    {
                        f = true;
                    }

                    break;
                }
            }

            mn = b[i];
            mx = a[i];
            for (lol j = i; j < n; j++)
            {
                mx = max(mx, a[j]);
                mn = min(mn, b[j]);
                if (a[j] == b[i])
                {
                    if (mx == mn && mx == b[i])
                    {
                        f = true;
                    }
                    break;
                }
            }

            ans &= f;
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
