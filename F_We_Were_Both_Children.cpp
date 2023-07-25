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
        lol a[n];
        map<lol, lol> mp;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }
        lol ans[n + 1];
        lol wow = 0;
        memset(ans, 0, sizeof(ans));
        for (auto e : mp)
        {
            lol c = e.first;
            for (lol i = c; i <= n; i += c)
            {
                ans[i] += e.second;
                wow = max(wow, ans[i]);
            }
        }
        cout << wow << '\n';
    }
}