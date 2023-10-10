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
        string a;
        cin >> a;
        lol p;
        cin >> p;
        lol n = a.size();
        lol pv[n + 1];
        for (lol i = 0; i <= n; i++)
        {
            pv[i] = i - 1;
        }
        lol nx[n + 1];
        for (lol i = 0; i <= n; i++)
        {
            nx[i] = i + 1;
        }
        lol s = 0, e = n;
        while (s != e - 1)
        {
            lol x = (s + e) / 2ll;
            if (((n * 1ll * x) - ((x * (x - 1)) / 2ll)) < p)
                s = x;
            else
                e = x;
        }
       
        lol i = 0;
        lol x = s;
        while (s > 0)
        {
            while (i < n && ((pv[i] == -1) || (a[i] >= a[pv[i]])))
                i++;
            if (i == n)
            {
                lol j = pv[i];
                while (s--)
                {
                    a[j] = '\n';
                    j = pv[j];
                }
                nx[j] = i;
                pv[i] = j;
            }
            else
            {
                lol j = pv[i];
                while (s > 0 && (j >= 0 && a[i] < a[j]))
                {
                    a[j] = '\n';
                    j = pv[j];
                    s--;
                }
                pv[i] = j;
                if (j >= 0)
                    nx[j] = i;
            }
        }
        p -= ((n * 1ll * x) - ((x * (x - 1)) / 2ll));
        for (i = 0; i < n; i++)
        {
            if (a[i] != '\n')
            {
                p--;
                if (p == 0)
                {
                    cout << a[i];
                }
            }
        }
    }
}