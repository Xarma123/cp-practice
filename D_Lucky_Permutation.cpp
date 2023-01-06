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
        bool vis[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            vis[i] = false;
        }
        lol ans = 0;
        bool f = false;
        for (lol i = 0; i < n; i++)
        {
            if (vis[i] == false)
            {
                lol c = 1;
                lol j = i;
                vis[i] = true;
                set<lol> x;
                while (a[j] != i + 1)
                {

                    x.insert(j);
                    c++;
                    j = a[j] - 1;
                    vis[j] = true;
                }

                x.insert(j);
                lol l = -3;
                for (auto e : x)
                {
                    if (e == l + 1)
                        f = true;
                    l = e;
                }

                ans += c - 1;
            }
        }
        if (f)
            cout << ans - 1 << endl;
        else
            cout << ans + 1 << endl;
    }
    return 0;
}