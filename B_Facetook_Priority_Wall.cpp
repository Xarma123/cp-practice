#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string me;
    cin >> me;
    lol m;
    cin >> m;
    map<string, lol> mp;
    while (m--)
    {
        string a;
        cin >> a;

        string b;
        cin >> b;

        lol p;
        if (b == "posted")
            p = -15;
        else if (b == "commented")
            p = -10;
        else
            p = -5;

        if (b != "likes")
            cin >> b;
        cin >> b;
        b.pop_back();
        b.pop_back();
        string w;
        cin >> w;
        if (a == me)
            mp[b] += p;
        else if (b == me)
            mp[a] += p;
        mp[a] = mp[a];
        mp[b] = mp[b];
    }

    vector<pair<lol, string>> q;
    for (auto e : mp)
    {
        q.push_back({e.second, e.first});
    }
    sort(q.begin(), q.end());
    for (lol i = 0; i < q.size(); i++)
    {
        if (q[i].second != me)
        {
            cout << q[i].second << endl;
        }
    }

    return 0;
}