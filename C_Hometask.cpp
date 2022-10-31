#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    vector<pair<lol, char>> v;
    for (lol i = 0; i < s.size(); i++)
    {
        lol j = i + 1;
        while (j < s.size() && s[j] == s[i])
        {
            j++;
        }
        v.push_back({j - i, s[i]});
        i = j - 1;
    }

    lol q;
    cin >> q;
    map<char, char> d;
    while (q--)
    {
        string ss;
        cin >> ss;
        d[ss[0]] = ss[1];
        d[ss[1]] = ss[0];
    }
    lol ans = 0;
    for (lol i = 0; i < v.size(); i++)
    {
        lol j = i + 1;
        lol a1 = 0, a2 = 0;
        a1 += v[i].first;
        while (j < v.size() && v[j].second == d[v[j - 1].second])
        {
            if ((j - i) % 2)
                a2 += v[j].first;
            else
                a1 += v[j].first;
            j++;
        }
        if (a1 != 0 && a2 != 0)
        {
            ans += min(a1, a2);
        }
        i = j - 1;
    }
    cout << ans;

    return 0;
}