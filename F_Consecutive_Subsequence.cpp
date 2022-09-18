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
    lol a[n];
    map<lol, lol> mp;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];

        mp[a[i]] = mp[a[i] - 1] + 1;
    }
    lol ans = 1;
    lol l = -1;
    for (auto e : mp)
    {
        if (ans <= e.second)
        {
            ans = e.second;
            l = e.first;
        }
    }
    cout << ans << endl;
    stack<lol> q;
    for (lol i = n - 1; i >= 0; i--)
    {
        if (a[i] == l)
        {
            q.push(i + 1);
            l--;
        }
    }
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }

    return 0;
}