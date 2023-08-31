#include <bits/stdc++.h>
using namespace std;
#define lol long long
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
        string a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<lol> ans[n];
        bool av[n];
        memset(av, false, sizeof(av));
        for (lol i = 0; i < n; i++)
        {
            lol p;
            for (p = 0; p < n; p++)
            {
                if (!av[p])
                {
                    av[p] = true;
                    break;
                }
            }
            ans[i].push_back(p + 1);
            for (lol j = 0; j < n; j++)
            {
                if (a[i][j] == '1')
                {
                    ans[j].push_back(p + 1);
                }
            }
        }

        for (lol i = 0; i < n; i++)
        {
            cout << ans[i].size() << " ";
            for (auto e : ans[i])
                cout << e << " ";
            cout << '\n';
        }
    }
}