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
    vector<string> x;
    lol i;
    for (i = 0; i < n; i++)
    {
        if (v[i].first > x.size())
        {
            break;
        }
        if (v[i].first == x.size())
            x.push_back(v[i].second);
        else
            x.insert(x.begin() + v[i].first, v[i].second);
    }
    if (i != n)
        cout << -1;
    else
    {
        lol q = 1e9;
        for (lol i = 0; i < n; i++)
        {
            cout << x[i] << " ";
            if (i)
            {
                if (v[i].first > v[i - 1].first)
                {
                    q--;
                }
            }
            cout << q << endl;
        }
    }

    return 0;
}