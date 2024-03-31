#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        string a[2];
        cin >> a[0] >> a[1];
        lol i = 0, j = 0;
        string f = "";
        while (i < 1 || j < n - 1)
        {

            f += a[i][j];
            if (i == 1)
            {
                j++;
            }
            else if (j == n - 1)
            {
                i++;
            }
            else if (a[i][j + 1] <= a[i + 1][j])
            {
                j++;
            }
            else
                i++;
        }
        f += a[i][j];

        bool pre[n];
        for (lol i = 0; i < n; i++)
        {

            if (a[0][i] == f[i])
                pre[i] = true;
            else
                pre[i] = false;
            if (i)
            {
                pre[i] &= pre[i - 1];
            }
        }
        bool suf[n];
        for (lol i = n - 1; i >= 0; i--)
        {
            if (a[1][i] == f[i + 1])
            {
                suf[i] = true;
            }
            else
                suf[i] = false;
            if (i < n - 1)
            {
                suf[i] &= suf[i + 1];
            }
        }
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            if (pre[i] && suf[i])
                ans++;
        }
        cout << f << "\n";
        cout << ans << '\n';
    }

    return 0;
}
