#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        lol b[n];
        for (lol i = 0; i < n; i++)
            cin >> a[i];
        for (lol i = 0; i < n; i++)
            cin >> b[i];

        vector<pair<lol, lol>> aa;
        for (lol i = 0; i < n; i++)
        {
            lol j = i + 1;
            while (j < n && a[i] == a[j])
                j++;
            aa.push_back({a[i], j - i});
            i = j - 1;
        }
        vector<pair<lol, lol>> bb;
        for (lol i = 0; i < n; i++)
        {
            lol j = i + 1;
            while (j < n && b[i] == b[j])
                j++;
            bb.push_back({b[i], j - i});
            i = j - 1;
        }
        bool ans = true;
        if (bb.size() <= aa.size())
        {
            map<lol, lol> ex;
            lol j = 0;
            for (lol i = 0; i < aa.size(); i++)
            {
                if (j == bb.size())
                {

                    ans = false;
                    break;
                }
                if (bb[j].first != aa[i].first)
                {
                    ex[aa[i].first] += aa[i].second;
                }
                else
                {
                    if (ex[aa[i].first] + aa[i].second < bb[j].second)
                    {
                        ex[aa[i].first] += aa[i].second;
                        continue;
                    }
                    ex[aa[i].first] = ex[aa[i].first] + aa[i].second - bb[j].second;
                    j++;
                }
            }

            for (auto e : ex)
                if (e.second)
                    ans = false;
            if (ans && j == bb.size())
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
            cout << "NO\n";
    }

    return 0;
}