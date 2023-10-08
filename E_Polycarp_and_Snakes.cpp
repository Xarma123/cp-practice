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
        string a[n];
        char mx = '\n';
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            for (lol j = 0; j < m; j++)
            {
                if (a[i][j] != '.')
                {
                    if (mx == '\n')
                        mx = a[i][j];
                    else
                        mx = max(mx, a[i][j]);
                }
            }
        }
        vector<vector<lol>> v;
        bool ans = true;

        for (char z = 'a'; z <= mx; z++)
        {
            lol l = -1, r = -1;
            lol c = 0;
            lol rw;
            for (lol i = 0; i < n; i++)
            {
                lol w = 0;
                for (lol j = 0; j < m; j++)
                {
                    if (a[i][j] == z)
                    {
                        if (l == -1)
                            l = j;
                        r = j;
                        w++;
                        rw = i;
                    }
                }
                if (w)
                    c++;
            }

            if (l == -1)
            {
                v.push_back({l, r});
                continue;
            }
            if (c == 1)
            {
                v.push_back({rw + 1, l + 1, rw + 1, r + 1});
                continue;
            }
            l = r = -1;
            c = 0;
            rw = -1;
            for (lol j = 0; j < m; j++)
            {
                lol w = 0;
                for (lol i = 0; i < n; i++)
                {
                    if (a[i][j] == z)
                    {
                        if (l == -1)
                            l = i;
                        r = i;
                        w++;
                        rw = j;
                    }
                }
                if (w)
                    c++;
            }
            if (c >= 2)
            {
                ans = false;
            }
            v.push_back({l + 1, rw + 1, r + 1, rw + 1});
        }
        if (ans)
        {
            char z = 'a';
            for (auto e : v)
            {
                if (e[0] == -1)
                {
                    z++;
                    continue;
                }
                if (e[0] == e[2])
                {
                    for (lol i = e[1] - 1; i <= e[3] - 1; i++)
                    {
                        if (a[e[0] - 1][i] == '.')
                        {
                            ans = false;
                            break;
                        }
                        if (a[e[0] - 1][i] < z)
                        {
                            ans = false;
                        }
                    }
                }
                else if (e[1] == e[3])
                {
                    for (lol i = e[0] - 1; i <= e[2] - 1; i++)
                    {
                        if (a[i][e[1] - 1] == '.')
                        {
                            ans = false;
                            break;
                        }

                        if (a[i][e[1] - 1] < z)
                        {
                            ans = false;
                        }
                    }
                }
                z++;
            }
            if (ans)
            {
                cout << "YES\n";
                cout << v.size() << '\n';
                for (auto e : v)
                {
                    if (e[0] == -1)
                    {
                        cout << v.back()[0] << " " << v.back()[1] << " " << v.back()[2] << " " << v.back()[3] << '\n';
                    }
                    else
                        cout << e[0] << " " << e[1] << " " << e[2] << " " << e[3] << '\n';
                }
            }
            else
                cout << "NO\n";
        }
        else
            cout << "NO\n";
    }
}