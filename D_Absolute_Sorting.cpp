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
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol l = 0;
        lol r = 1e9;
        bool ans = true;
        for (lol i = 0; i < n - 1; i++)
        {
            if (a[i] < a[i + 1])
            {
                lol nl = 0;
                lol nr = (a[i] + a[i + 1]) / 2;
                if (nl > r || nr < l)
                {
                    ans = false;
                    break;
                }
                else
                {
                    l = max(l, nl);
                    r = min(r, nr);
                }
            }
            else if (a[i] > a[i + 1])
            {
                lol nl = ceill((a[i] + a[i + 1]) / (long double)2);
                lol nr = 1e9;
                if (nl > r || nr < l)
                {
                    ans = false;
                    break;
                }
                else
                {
                    l = max(l, nl);
                    r = min(r, nr);
                }
            }
        }
        if (ans)
            cout << l << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}