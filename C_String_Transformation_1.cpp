#include <bits/stdc++.h>
using namespace std;
#define lol long long
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
        string a, b;
        cin >> a >> b;
        map<char, set<char>> mp;
        bool ans = true;
        for (lol i = 0; i < n && ans; i++)
        {
            if (a[i] != b[i])
            {
                if (b[i] < a[i])
                {
                    ans = false;
                }
                else
                {
                    mp[a[i]].insert(b[i]);
                }
            }
        }
        if (ans)
        {
            lol c = 0;
            for (char i = 'a'; i <= 'z'; i++)
            {
                if (mp[i].size() == 0)
                    continue;
                char j = (*mp[i].begin());
                mp[i].erase(j);
                c++;
                for (auto e : mp[i])
                    mp[j].insert(e);
            }
            cout << c << '\n';
        }
        else
            cout << -1 << '\n';
    }
}