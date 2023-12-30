#include <bits/stdc++.h>
using namespace std;
#define lol long long
map<lol, vector<string>> mp;
vector<string> solve(lol n)
{
    if (n == 1)
        return {"1"};
    if (n == 3)
    {
        vector<string> v;
        v.push_back("169");
        v.push_back("196");
        v.push_back("961");
        return v;
    }
    if (mp.count(n))
    {
        return mp[n];
    }
    vector<string> v = solve(n - 2);
    vector<string> ans;
    string a = v[0];
    a.insert(1, "0");
    a.insert(a.size() - 1, "0");
    ans.push_back(a);
    for (auto e : v)
    {
        ans.push_back((e + "00"));
    }
    a = v.back();
    a.insert(1, "0");
    a.insert(a.size() - 1, "0");
    ans.push_back(a);
    return (mp[n] = ans);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        vector<string> v = solve(n);
        for (auto e : v)
            cout << e << '\n';
    }

    return 0;
}
