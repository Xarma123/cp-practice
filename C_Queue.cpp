#include <bits/stdc++.h>
#define lol long long
using namespace std;
// a
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    vector<pair<lol, string>> v;
    for (lol i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        lol q;
        cin >> q;
        v.push_back({q, s});
    }
    sort(v.begin(), v.end());
    lol q = 1e9;
    vector<pair<string, lol>> x;
    lol i;
    for (i = 0; i < n; i++)
    {
        if (v[i].first > x.size())
        {
            break;
        }
        if (v[i].first == x.size())
        {
            x.push_back({v[i].second, (q--)});
        }
        else
        {
            x.insert(x.begin() + v[i].first, {v[i].second, (q--)});
        }
    }
    if (i != n)
        cout << -1;
    else
    {

        for (lol i = 0; i < n; i++)
        {
            cout << x[i].first << " " << x[i].second << endl;
        }
    }

    return 0;
}