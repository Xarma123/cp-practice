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
        lol n, m;
        cin >> n >> m;
        lol a[n - 1], b[n];
        for (lol i = 0; i < n - 1; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        sort(a, a + n - 1);
        sort(b, b + n);
        lol k = 0;
        bool use[n];
        memset(use, false, sizeof(use));
        lol ans = 0;
        for (lol i = 0; i < n - 1 && k < n; i++)
        {
            lol j = upper_bound(b + k, b + n, a[i]) - b;
            if (j < n)
            {
                use[j] = true;
                ans++;
            }
            k = j + 1;
        }
        vector<lol> r;
        for (lol i = 0; i < n; i++)
        {
            if (!use[i])
                r.push_back(b[i]);
        }

        if (m >= r.back())
        {
            cout << (r.back() - 1) * 1ll * (n - ans - 1) + (m - (r.back() - 1)) * 1ll * (n - ans) << '\n';
        }
        else
        {
            cout << m * 1ll * (n - ans - 1) << '\n';
        }
    }

    return 0;
}
