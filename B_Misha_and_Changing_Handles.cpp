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
    map<string, string> mp;
    vector<string> q;
    while (n--)
    {
        string a, b;
        cin >> a >> b;
        q.push_back(a);
        mp[a] = b;
    }
    set<string> x;
    vector<vector<string>> ans;
    for (lol i = 0; i < q.size(); i++)
    {
        if (!x.count(q[i]))
        {
            string a = q[i];
            while (mp.count(a))
            {
                x.insert(a);
                a = mp[a];
            }
            x.insert(a);
            ans.push_back({q[i], a});
        }
    }
    cout << ans.size() << endl;
    for (auto e : ans)
        cout << e[0] << " " << e[1] << endl;

    return 0;
}