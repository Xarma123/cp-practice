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
        lol n, m, k;
        cin >> n >> m >> k;
        lol a[n], b[m];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        bool f1[k + 1];
        memset(f1, false, sizeof(f1));
        for (lol i = 0; i < n; i++)
        {
            if (a[i] <= k)
                f1[a[i]] = true;
        }
        bool f2[k + 1];
        memset(f2, false, sizeof(f2));
        for (lol i = 0; i < m; i++)
        {
            if (b[i] <= k)
                f2[b[i]] = true;
        }
        lol a1 = 0, b1 = 0;
        bool ans = true;
        for (lol i = 1; i <= k; i++)
        {
            if (f1[i] && f2[i] == false)
                a1++;
            else if (f2[i] && f1[i] == false)
                b1++;
            else if (f1[i] == false && f2[i] == false)
            {
                ans = false;
            }
        }
        if (max(a1, b1) > (k / 2ll))
        {
            ans = false;
        }
        cout << ((ans) ? "YES" : "NO") << endl;
    }

    return 0;
}
