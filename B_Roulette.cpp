#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    vector<lol> v[n];
    for (lol i = 0; i < n; i++)
    {
        lol c;
        cin >> c;
        for (lol j = 0; j < c; j++)
        {
            lol va;
            cin >> va;
            v[i].push_back(va);
        }
    }
    lol x;
    cin >> x;
    vector<pair<lol, lol>> v2;
    for (lol i = 0; i < n; i++)
    {
        lol j;
        for (j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] == x)
                break;
        }
        if (j < v[i].size())
        {
            v2.push_back({v[i].size(), i + 1});
        }
    }
    sort(v2.begin(), v2.end());
    for (lol i = 0; i < v2.size(); i++)
    {
        lol j = i + 1;
        while (j < v2.size() && v2[j].first == v2[i].first)
            j++;
        cout << j << '\n';
        for (lol k = 0; k < j; k++)
        {
            cout << v2[k].second << " ";
        }
        break;
    }
    if (v2.size() == 0)
        cout << 0;
}