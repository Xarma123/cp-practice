#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    string a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<pair<lol, lol>> r, c;
    for (lol i = 0; i < n; i++)
    {
        bool r1 = false, c1 = false;
        for (lol j = 0; j < n; j++)
        {
            if (a[i][j] == '.' && !r1)
            {
                r.push_back({i, j});
                r1 = true;
            }
            if (a[j][i] == '.' && !c1)
            {
                c.push_back({j, i});
                c1 = true;
            }
        }
    }
    if (r.size() == n)
    {
        for (auto e : r)
            cout << e.first + 1 << " " << e.second + 1 << '\n';
    }
    else if (c.size() == n)
    {
        for (auto e : c)
            cout << e.first + 1 << " " << e.second + 1 << '\n';
    }
    else
        cout << -1;

    return 0;
}