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
        lol n, m;
        cin >> n >> m;
        lol c[n + 1];
        memset(c, 0, sizeof(c));
        map<lol, vector<lol>> mp;
        while (m--)
        {
            lol x, y;
            cin >> x >> y;
            mp[x].push_back(y);
            mp[y].push_back(x);
            c[x]++;
            c[y]++;
        }
        for (lol i = 1; i <= n; i++)
        {
            if (c[i] > 1)
            {
                lol v = -1;
                for (auto e : mp[i])
                {
                    if (c[e] > 2)
                    {
                        if (v == -1)
                            v = c[e];
                        else if (v != c[e])
                        {
                            v = -1;
                            break;
                        }
                    }
                    else
                    {
                        v = -1;
                        break;
                    }
                }
                if (v != -1)
                {
                    cout << c[i] << " " << v - 1 << '\n';
                    break;
                }
            }
        }
    }

    return 0;
}