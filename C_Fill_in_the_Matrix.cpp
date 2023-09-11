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
        lol n, m;
        cin >> n >> m;
        lol a[n][m];
        for (lol i = 0; i < n; i++)
        {
            if (i >= m - 1)
            {
                for (lol j = 0; j < m; j++)
                {
                    if (i - 1 >= 0)
                        a[i][j] = a[i - 1][j];
                    else
                        a[i][j] = 0;
                }
                continue;
            }
            lol c = 0;
            for (lol j = i + 1; j < m; j++)
            {
                a[i][j] = (c++);
            }
            lol mx = m - 1;
            for (lol j = i; j >= 0; j--)
            {
                a[i][j] = (mx--);
            }
        }
        vector<lol> v;
        for (lol j = 0; j < m; j++)
        {
            set<lol> x;
            for (lol i = 0; i < n; i++)
            {
                x.insert(a[i][j]);
            }
            lol c = 0;
            while (x.size() && (*x.begin()) == c)
            {
                x.erase(x.begin());
                c++;
            }
            v.push_back(c);
        }

        bool us[m + 1];
        memset(us, false, sizeof(us));
        for (auto e : v)
        {
            us[e] = true;
        }
        for (lol i = 0; i <= m; i++)
        {
            if (!us[i])
            {
                cout << i << '\n';
                break;
            }
        }
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << '\n';
        }
    }
}