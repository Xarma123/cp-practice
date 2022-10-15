#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, vector<lol>> mp;
lol n;
map<lol, bool> memo;
bool solve(lol l)
{
    if (memo.count(l))
        return memo[l];
    if (l == n)
        return true;
    if (l > n)
        return false;
    for (auto e : mp[l])
    {
        if (solve(e + 1))
            return memo[l] = true;
    }
    return memo[l] = false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        mp.clear();
        memo.clear();
        cin >> n;
        lol b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
            if (i + b[i] < n)
            {
                mp[i].push_back(i + b[i]);
            }
            if (i - b[i] >= 0)
                mp[i - b[i]].push_back(i);
        }
        if (solve(0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}