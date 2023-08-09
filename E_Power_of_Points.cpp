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
        lol n;
        cin >> n;
        pair<lol, lol> x[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> x[i].first;
            x[i].second = i;
        }
        sort(x, x + n);
        lol gequal[n], lequal[n];
        lol ans[n];
        memset(ans, 0, sizeof(ans));
        for (lol i = 0; i < n; i++)
        {
            lol j = i + 1;
            while (j < n && x[j].first == x[i].first)
                j++;
            for (lol k = i; k < j; k++)
            {
                gequal[k] = j - i + n - j;
                lequal[k] = i + j - i;
                // ans[k] += (j - i) * 1ll * (n);
            }
            i = j - 1;
        }

        for (lol i = 0; i < n; i++)
        {
            lol j = i + 1;
            while (j < n && x[j].first == x[i].first)
                j++;
            lol f = 1;
            if (i)
                f = x[i].first - x[i - 1].first;

            ans[0] += f * 1ll * gequal[i];
            ans[i] -= f * 1ll * gequal[i];
            if (j < n)
            {
                f = x[j].first - x[i].first ;
        
                ans[j] += lequal[i] * 1ll * f;
            }
            i = j - 1;
        }
        for (lol i = 1; i < n; i++)
        {
            ans[i] += ans[i - 1];
        }

        for (lol i = 0; i < n; i++)
        {
            lol j = i + 1;
            while (j < n && x[j].first == x[i].first)
                j++;
            for (lol k = i; k < j; k++)
            {
                ans[k] += (n);
            }
            i = j - 1;
        }
        for (lol i = 0; i < n; i++)
        {
            x[i].first = x[i].second;
            x[i].second = ans[i];
        }
        sort(x, x + n);
        for (lol i = 0; i < n; i++)
        {
            cout << x[i].second << " ";
        }
        cout << '\n';
    }
}