#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {

        char c = 'a';
        map<lol, vector<char>> mp;
        lol n;
        cin >> n;
        string ans = "";
        for (lol i = 0; i < n; i++)
        {
            lol v;
            cin >> v;
            if (v == 0)
            {
                ans += c;
                mp[1].push_back(c);
                c++;
            }
            else
            {
                ans += mp[v].back();
                mp[v + 1].push_back(mp[v].back());
                mp[v].pop_back();
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
