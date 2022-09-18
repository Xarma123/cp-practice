#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, m;
    cin >> n >> m;
    lol a[n][m];
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (lol i = m - 1; i >= 0; i--)
    {
        for (lol j = n - 1; j >= 0; j--)
        {
            if (a[j][i] == 0)
            {
                a[j][i] = min(a[j + 1][i] - 1, a[j][i + 1] - 1);
            }
        }
    }
    bool ans = true;
    lol s = 0;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            s += a[i][j];
            if (j > 0)
            {
                if (a[i][j] <= a[i][j - 1])
                    ans = false;
            }
        }
    }
    if (ans)
    {
        for (lol i = 0; i < m; i++)
        {
            for (lol j = 0; j < n; j++)
            {
                if (j > 0)
                {
                    if (a[j][i] <= a[j - 1][i])
                        ans = false;
                }
            }
        }
    }
    if(ans)
    cout<<s;
    else
    cout<<-1;

    return 0;
}