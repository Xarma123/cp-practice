#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        lol l[k], r[k];
        for (lol i = 0; i < k; i++)
        {
            cin >> l[i];
        }
        for (lol i = 0; i < k; i++)
        {
            cin >> r[i];
        }
        map<lol, lol> mp;
        for (lol i = 0; i < k; i++)
        {
            lol a = l[i];
            lol b = r[i];
            while (a <= b)
            {
                mp[a] = b;
                a++;
                b--;
            }
        }
        lol q;
        cin >> q;
        lol c[n + 1];
        memset(c, 0, sizeof(c));
        while (q--)
        {
            lol x;
            cin >> x;
            lol j = lower_bound(l, l + k, x) - l;
            if (j == k)
                j--;
            else if (l[j] > x)
                j--;
            lol lr = min(x, l[j] + r[j] - x);
            lol lrr = max(x, l[j] + r[j] - x);
            c[lrr] += -1;
            c[lr - 1] += 1;
        }
        for (lol i = 1; i <= n; i++)
        {
            c[i] += c[i - 1];
        }
        for (lol i = 0; i < n; i++)
        {
            if (c[i] % 2 != 0)
            {
                if (mp.count(i+1))
                {
                    swap(s[i], s[mp[i+1] - 1]);
                }
            }
        }
        cout << s << '\n';
    }
}