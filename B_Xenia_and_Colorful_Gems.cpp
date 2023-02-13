#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol cal(lol a, lol b, lol c)
{
    return ((a - b) * 1ll * (a - b) + (b - c) * 1ll * (b - c) + (c - a) * 1ll * (c - a));
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        vector<lol> a(n1), b(n2), c(n3);
        for (lol i = 0; i < n1; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < n2; i++)
        {
            cin >> b[i];
        }
        for (lol i = 0; i < n3; i++)
        {
            cin >> c[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        lol ans = LONG_LONG_MAX;
        for (lol i = 0; i < n1; i++)
        {
            lol j = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            lol k = upper_bound(c.begin(), c.end(), a[i]) - c.begin();
            if (j)
            {
                if (k != n3)
                {
                    ans = min(ans, cal(a[i], b[j - 1], c[k]));
                }
            }
            if (j != n2 && k != n3)
            {
                ans = min(ans, cal(a[i], b[j], c[k]));
            }
            if (k)
            {
                k--;
                if (j != n2)
                {
                    ans = min(ans, cal(a[i], b[j], c[k]));
                }
            }
            j = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
            k = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
            if (j != n2)
            {
                if (k)
                {
                    ans = min(ans, cal(a[i], b[j], c[k - 1]));
                }
            }
            if (j != n2 && k != n3)
            {
                ans = min(ans, cal(a[i], b[j], c[k]));
            }
            if (j)
            {
                j--;
                if (k != n3)
                {
                    ans = min(ans, cal(a[i], b[j], c[k]));
                }
            }
        }
        swap(a, b);
        swap(n1, n2);
        for (lol i = 0; i < n1; i++)
        {
            lol j = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            lol k = upper_bound(c.begin(), c.end(), a[i]) - c.begin();
            if (j)
            {
                if (k != n3)
                {
                    ans = min(ans, cal(a[i], b[j - 1], c[k]));
                }
            }
            if (j != n2 && k != n3)
            {
                ans = min(ans, cal(a[i], b[j], c[k]));
            }
            if (k)
            {
                k--;
                if (j != n2)
                {
                    ans = min(ans, cal(a[i], b[j], c[k]));
                }
            }
            j = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
            k = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
            if (j != n2)
            {
                if (k)
                {
                    ans = min(ans, cal(a[i], b[j], c[k - 1]));
                }
            }
            if (j != n2 && k != n3)
            {
                ans = min(ans, cal(a[i], b[j], c[k]));
            }
            if (j)
            {
                j--;
                if (k != n3)
                {
                    ans = min(ans, cal(a[i], b[j], c[k]));
                }
            }
        }
        swap(a, c);
        swap(n1, n3);
        for (lol i = 0; i < n1; i++)
        {
            lol j = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            lol k = upper_bound(c.begin(), c.end(), a[i]) - c.begin();
            if (j)
            {
                if (k != n3)
                {
                    ans = min(ans, cal(a[i], b[j - 1], c[k]));
                }
            }
            if (j != n2 && k != n3)
            {
                ans = min(ans, cal(a[i], b[j], c[k]));
            }
            if (k)
            {
                k--;
                if (j != n2)
                {
                    ans = min(ans, cal(a[i], b[j], c[k]));
                }
            }
            j = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
            k = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
            if (j != n2)
            {
                if (k)
                {
                    ans = min(ans, cal(a[i], b[j], c[k - 1]));
                }
            }
            if (j != n2 && k != n3)
            {
                ans = min(ans, cal(a[i], b[j], c[k]));
            }
            if (j)
            {
                j--;
                if (k != n3)
                {
                    ans = min(ans, cal(a[i], b[j], c[k]));
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}