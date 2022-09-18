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

    lol mxn = (long long)ceil(log2l(n));
    lol sparseTable[n][mxn + 1];
    for (lol i = 0; i <= mxn; i++)
    {
        for (lol j = 0; j + (1 << i) - 1 < n; j++)
        {
            if (i == 0)
                sparseTable[j][i] = a[j];
            else
            {
                sparseTable[j][i] = max(sparseTable[j][i - 1], sparseTable[j + (1 << (i - 1))][i - 1]);
            }
        }
    }
    lol ans = 0;
    while (m--)
    {
        lol a1, b;
        cin >> a1 >> b;
        a1--;
        b--;
        if (a1 < b)
        {
            b--;
            if (a1 == b)
                ans++;
            else
            {
                lol x = log2l(b - a1 + 1);
                lol mx = max(sparseTable[a1][x], sparseTable[b + 1 - (1 << x)][x]);
                if (mx == a[a1])
                    ans++;
            }
        }
        else if (a1 == b)
            ans++;
        else
        {
            b++;
            if (a1 == b)
                ans++;
            else
            {
                swap(a1, b);
                lol x = log2l(b - a1 + 1);
                lol mx = max(sparseTable[a1][x], sparseTable[b + 1 - (1 << x)][x]);
                if (mx == a[b])
                    ans++;
            }
        }
    }
    cout << ans;

    return 0;
}