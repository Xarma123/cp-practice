#include <bits/stdc++.h>
using namespace std;
#define lol  long long
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
        lol sub = 0;
        pair<lol, lol> b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i].first = a[i];
            b[i].second = i;
        }
        lol k;
        cin >> k;
        sort(b, b + n);
        lol p[n];
        for (lol i = 0; i < n; i++)
        {
            if (i == 0)
            {
                p[i] = b[i].second;
            }
            else
                p[i] = max(p[i - 1], b[i].second);
        }
        lol suf[n];
        for (lol i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
                suf[i] = a[i];
            else
                suf[i] = min(a[i], suf[i + 1]);
        }
        lol c[n];
        memset(c, 0, sizeof(c));
        lol i = 0;
        while (i < n && k > 0)
        {
            if (suf[i] < sub)
                break;
            lol mn = suf[i] - sub;
            if (mn < 0)
                break;
            lol x = k / mn;
            if (x == 0)
                break;
            lol s = 0, e = mn;
            while (s != e - 1)
            {
                lol m = (s + e) / 2;
                if (k / (m + mn) == x)
                {
                    s = m;
                }
                else
                    e = m;
            }
            mn += s;

            s = -1, e = n;
            while (s != e - 1)
            {
                lol m = (s + e) / 2;
                if (m == -1)
                    s = m;
                else if (m == n)
                    e = m;
                else if (b[m].first < sub || b[m].first - sub <= mn)
                    s = m;
                else
                    e = m;
            }
            if (s == -1)
                break;
            lol j = p[s];
            if (j < i)
                break;
            c[j] += x;
            i = j + 1;
            k %= a[j]-sub;
            sub += a[j]-sub;
        }
        lol tot = 0;
        for (lol i = n - 1; i >= 0; i--)
        {
            if (c[i] > 0)
                c[i] -= tot;
            tot += c[i];
            if (i < n - 1)
                c[i] += c[i + 1];
        }
        for (lol i = 0; i < n; i++)
        {
            cout << c[i] << " ";
        }
        cout << '\n';
    }
}