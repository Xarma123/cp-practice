#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, r, avg;
    cin >> n >> r >> avg;
    lol sum = 0;
    map<lol, lol> mp;
    for (lol i = 0; i < n; i++)
    {
        lol q;
        cin >> q;
        sum += q;
        lol b;
        cin >> b;
        mp[b] += r - q;
    }
    lol ans = 0;
    auto it = mp.begin();
    while (n * avg > sum)
    {
        lol b = (*it).first;
        lol ex = (*it).second;
        if (ex + sum <= n * avg)
        {
            sum = ex + sum;
            ans += b * 1ll * ex;
        }
        else
        {
            ans += (n * 1ll * avg - sum) * 1ll * b;
            sum = n * 1ll * avg;
        }
        it++;
    }
    cout << ans;

    return 0;
}