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
    vector<pair<lol, lol>> h, v;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < n; j++)
        {
            
            if (a[i][j] == '.')
            {
                if (h.size() == i)
                {
                    h.push_back({i, j});
                }
            }
            if (a[j][i] == '.')
            {

                if (v.size() == i)
                {
                    v.push_back({j, i});
                }
            }
        }
    }
    if (v.size() != n && h.size() != n)
        cout << -1;
    else if (v.size() == n)
    {
        for (auto e : v)
        {
            cout << e.first + 1 << " " << e.second + 1 << endl;
        }
    }
    else
    {
        for (auto e : h)
        {
            cout << e.first + 1 << " " << e.second + 1 << endl;
        }
    }

    return 0;
}