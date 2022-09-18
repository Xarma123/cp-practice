#include <bits/stdc++.h>
#define lol long long
using namespace std;
long double cal(pair<lol, lol> a, pair<lol, lol> b)
{
    lol x1 = a.first;
    lol y1 = a.second;
    lol x2 = b.first;
    lol y2 = b.second;
    return sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    vector<pair<lol, lol>> v;
    while (n--)
    {
        lol x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    long double ans = 0;
    set<pair<pair<lol, lol>, pair<lol, lol>>> mp;
    for (lol i = 1; i < v.size(); i++)
    {
        ans += k * (cal(v[i], v[i - 1]));
    }
    ans = ans / (long double)50;
    cout << setprecision(20) << ans;

    return 0;
}