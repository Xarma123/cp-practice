#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, m, k;
    cin >> n >> m >> k;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol b[m];
    for (lol i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    map<lol, lol> mp1;
    for (lol i = 0; i < n; i++)
    {
        if (a[i])
        {
            lol j = i + 1;
            if (j < n)
            {
                while (a[j] == 1)
                {
                    j++;
                    if (j == n)
                        break;
                }
            }
            lol c = 1;

            for (lol l = j - i; l >= 1; l--)
            {
                mp1[l] += c;
                c++;
            }
            i = j;
        }
    }
    map<lol, lol> mp2;
    for (lol i = 0; i < m; i++)
    {
        if (b[i])
        {
            lol j = i + 1;
            if (j < m)
            {
                while (b[j] == 1)
                {
                    j++;
                    if (j == m)
                        break;
                }
             
            }
            lol c = 1;

            for (lol l = j - i; l >= 1; l--)
            {  
                mp2[l] += c;

                c++;
            }
            i = j;
        }
    }

    set<lol> v;
    for (lol i = 1; i * i <= k; i++)
    {
        if (k % i == 0)
        {

            v.insert(i);

            v.insert(k / i);
        }
    }

    lol ans = 0;
    for (auto i = v.begin(); i != v.end(); i++)
    {
        lol p = (*i);
        lol q = k / p;
        ans += mp1[p] * 1ll * mp2[q];
    }
    cout << ans;

    return 0;
}