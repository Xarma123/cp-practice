#include <bits/stdc++.h>
#define lol long long
using namespace std;
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
        lol a[n][n];
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < n - 1; j++)
            {
                cin >> a[i][j];
            }
        }
        lol ans[n];
        for (lol q = 1; q <= n; q++)
        {
            set<lol> x;
            for (lol i = 0; i < n; i++)
            {
                lol j;
                for (j = 0; j < n - 1; j++)
                {
                    if (a[i][j] == q)
                        break;
                }
                if (j != n - 1)
                    x.insert(n - 1 - (j + 1));
            }
            if (x.size() == 1)
            {
                if ((*x.begin()))
                {
                    ans[0] = q;
                }
                else
                {
                    ans[n - 1] = q;
                }
            }
            else
            {
                ans[n - 1 - (*x.rbegin())] = q;
            }
        }
        for (lol i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}