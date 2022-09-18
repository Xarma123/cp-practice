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
        lol n, T;
        cin >> n >> T;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        lol ans[n];
        lol g = 0;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] < T / 2)
                ans[i] = 0;
            else if (a[i] == T / 2)
            {
                if (T % 2 != 0)
                {
                    ans[i] = 0;
                }
                else
                {
                    ans[i] = g;
                    g = 1 - g;
                }
            }
            else
            {
                ans[i] = 1;
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