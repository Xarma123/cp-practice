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
    string s;
    cin >> s;
    lol q;
    cin >> q;
    vector<pair<vector<lol>, char>> v;
    while (q--)
    {
        lol t, x;
        char c;
        cin >> t >> x >> c;

        v.push_back({{t, x}, c});
        if (t == 1)
            s[x - 1] = c;
    }

    for (lol i = v.size() - 1; i >= 0; i--)
    {
        if (v[i].first[0] != 1)
        {
            if (v[i].first[0] == 2)
                transform(s.begin(), s.end(), s.begin(), ::tolower);
            else
                transform(s.begin(), s.end(), s.begin(), ::toupper);
            for (lol j = i + 1; j < v.size(); j++)
            {
                if (v[j].first[0] == 1)
                {
                    s[v[j].first[1] - 1] = v[j].second;
                }
            }
            break;
        }
    }
    cout << s;
}