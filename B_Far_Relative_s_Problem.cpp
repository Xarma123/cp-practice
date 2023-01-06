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
    vector<pair<lol, lol>> m, f;
    while (n--)
    {
        char c;
        cin >> c;
        lol l, r;
        cin >> l >> r;
        if (c == 'M')
        {
            m.push_back({l, r});
        }
        else
            f.push_back({l, r});
    }
    lol ans = 0;
    for (lol i = 0; i <= 366; i++)
    {
        lol a = 0;
        for (auto e : m)
        {
            if (e.first <= i && e.second >= i)
                a++;
        }
        lol b = 0;
        for (auto e : f)
        {
            if (e.first <= i && e.second >= i)
                b++;
        }
        ans = max(ans, min(a, b));
    }
    cout << 2ll * ans;

    return 0;
}