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
        map<lol, vector<lol>> f;
        lol ans;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            f[a[i]].push_back(i + 1);
        }
        for (auto e : f)
        {
            if (e.second.size() == 1)
                ans = e.second[0];
        }
        cout << ans << '\n';
    }
}