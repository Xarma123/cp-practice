#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, q;
    cin >> n >> q;
    lol r[2][n];
    memset(r, 0, sizeof(r));
    set<pair<pair<lol, lol>, pair<lol, lol>>> mp;
    while (q--)
    {
        lol x, y;
        cin >> x >> y;
        x--;
        y--;
        r[x][y] = 1 - r[x][y];
        if (r[x][y] == 1)
        {
            lol X = 1 - x;
            for (lol i = y - 1; i < y + 2; i++)
            {
                if (i < 0 || i >= n)
                    continue;
                if (r[X][i])
                {
                    if (y <= i)
                    {
                        if (y == i)
                        {
                            if (x == 0)
                            {
                                mp.insert({{y, x}, {i, X}});
                            }
                            else
                                mp.insert({{i, X}, {y, x}});
                        }
                        else
                            mp.insert({{y, x}, {i, X}});
                    }
                    else
                        mp.insert({{i, X}, {y, x}});
                }
            }
        }
        else
        {
            lol X = 1 - x;
            for (lol i = y - 1; i < y + 2; i++)
            {
                if (i < 0 || i >= n)
                    continue;
                if (r[X][i])
                {
                    if (y <= i)
                    {
                        if (y == i)
                        {
                            if (x == 0)
                            {
                                mp.erase({{y, x}, {i, X}});
                            }
                            else
                                mp.erase({{i, X}, {y, x}});
                        }
                        else
                            mp.erase({{y, x}, {i, X}});
                    }
                    else
                        mp.erase({{i, X}, {y, x}});
                }
            }
        }
        if (mp.size())
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }

    return 0;
}