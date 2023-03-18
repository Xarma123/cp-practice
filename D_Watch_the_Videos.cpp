#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    lol ans = n;
    for (lol i = 0; i < n; i++)
    {
        ans += a[i];
    }
    lol st = 0, e = n ;
    while (st != e - 1)
    {
        lol md = (st + e) / 2;
        if (md == n )
            e = md;
        else
        {
            lol i = 0, j = md;
            bool f = true;
            bool all = true;
            while (i < j)
            {
                if (a[i] + a[j] > m)
                {
                    all = false;
                }
                if (f)
                {
                    f = false;
                    i++;
                }
                else
                {
                    f = true;
                    j--;
                }
            }
            bool al2 = true;
            f = false;
            i = 0, j = md;
            while (i < j)
            {
                if (a[i] + a[j] > m)
                {
                    al2 = false;
                }
                if (f)
                {
                    f = false;
                    i++;
                }
                else
                {
                    f = true;
                    j--;
                }
            }

            if (all || al2)
                st = md;
            else
                e = md;
        }
    }
    ans -= st;
    cout << ans;

    return 0;
}