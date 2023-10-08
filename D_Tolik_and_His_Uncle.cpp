#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    vector<pair<lol, lol>> v;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            v.push_back({i + 1, j + 1});
        }
    }
    lol i = 0, j = v.size() - 1;
    while (i <= j)
    {
        if (i == j)
        {
            cout << v[i].first << ' ' << v[i].second << '\n';
            i++;
        }
        else
        {
            cout << v[i].first << " " << v[i].second << '\n';
            cout << v[j].first << " " << v[j].second << '\n';
            i++;
            j--;
        }
    }
    
}