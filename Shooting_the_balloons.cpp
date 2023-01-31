#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol s = -1, e = 1e18;
    while (s != e - 1)
    {
        lol m = (s + e) / 2;
        if (m == -1)
            s = m;
        else
        {
            lol v = 0;
            lol c = 0;
            lol j = 0;
            for (lol i = 0; i < n; i++)
            {
                c += a[i];
                while (c >= m + 1 && j <= i)
                {
                    if (j >= 0)
                        c -= a[j];
                    j++;
                }
                v += i - j + 1;
            }
            if (v >= k)
                e = m;
            else
                s = m;
          
        }
    }
    cout << e;

    return 0;
}