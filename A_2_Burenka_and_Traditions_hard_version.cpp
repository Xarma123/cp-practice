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
        lol a[n];
        lol ans = n;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        set<lol> x[n + 4];
        lol k = 0;
        x[k].insert(0ll);
        lol c = 0;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                c = 0;
                ans--;
                k++;
                x[k].insert(c);
            }
            else
            {
                c ^= a[i];
                if (x[k].count(c))
                {
                    ans--;
                    c = 0;
                    k++;
                    x[k].insert(c);
                }
                else
                    x[k].insert(c);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}