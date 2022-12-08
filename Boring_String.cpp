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
        string s;
        cin >> s;
        map<char, vector<lol>> mp;
        for (lol i = 0; i < n; i++)
        {
            lol j = i + 1;
            while (j < n && s[j] == s[i])
                j++;
            mp[s[i]].push_back(j - i);
            i = j - 1;
        }
        lol ans = 0;
        for (auto e : mp)
        {
            sort(e.second.rbegin(), e.second.rend());
            lol v = e.second[0] - 1;
            if (e.second.size() > 1)
            {
                v = max(v, e.second[1]);
            }
            ans = max(ans, v);
        }
        cout << ans << endl;
    }

    return 0;
}