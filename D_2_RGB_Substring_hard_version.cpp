#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol q;
    cin >> q;
    while (q--)
    {
        lol n, k;
        cin >> n >> k;
        string a;
        cin >> a;
        lol ans = LONG_LONG_MAX;

        lol c[3][n + 1];
        c[0][0] = 0;
        c[1][0] = 0;
        c[2][0] = 0;
        for (lol i = 1; i <= n; i++)
        {
            c[0][i] = c[0][i - 1];
            if (i % 3 == 1 && a[i - 1] != 'R')
                c[0][i]++;
            else if (i % 3 == 2 && a[i - 1] != 'G')
                c[0][i]++;
            else if (i % 3 == 0 && a[i - 1] != 'B')
                c[0][i]++;

            c[1][i] = c[1][i - 1];
            if (i % 3 == 1 && a[i - 1] != 'G')
                c[1][i]++;
            else if (i % 3 == 2 && a[i - 1] != 'B')
                c[1][i]++;
            else if (i % 3 == 0 && a[i - 1] != 'R')
                c[1][i]++;

            c[2][i] = c[2][i - 1];
            if (i % 3 == 1 && a[i - 1] != 'B')
                c[2][i]++;
            else if (i % 3 == 2 && a[i - 1] != 'R')
                c[2][i]++;
            else if (i % 3 == 0 && a[i - 1] != 'G')
                c[2][i]++;
        }

        for (lol i = 0; i + k <= n; i++)
        {
            ans = min(ans, c[0][i + k] - c[0][i]);
            ans = min(ans, c[1][i + k] - c[1][i]);
            ans = min(ans, c[2][i + k] - c[2][i]);
        } 
        cout<<ans<<endl;
    }

    return 0;
}