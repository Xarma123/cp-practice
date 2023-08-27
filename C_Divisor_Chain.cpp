#include <bits/stdc++.h>
using namespace std;
#define lol long long
vector<lol> ans;
void solve(lol x)
{
    if (x == 1)
    {
        return;
    }
    if ((x & (x - 1)) == 0)
    {
        ans.push_back(x - (x / 2ll));
        solve(x - (x / 2ll));
        return;
    }
    lol v = x;
    lol c = 0;
    while (v % 2 == 0)
    {
        c++;
        v /= 2;
    }
    ans.push_back(x - (1ll << c));
    solve(x - (1ll << c));
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
        lol x;
        cin >> x;
        ans.clear();
        ans.push_back(x);
        solve(x);
        cout << ans.size() << '\n';
        for (auto e : ans)
            cout << e << " ";
        cout << '\n';
    }
    return 0;
}