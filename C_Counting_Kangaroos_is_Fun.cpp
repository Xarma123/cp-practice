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
    vector<lol> v;
    while (n--)
    {
        lol x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    lol ans = v.size();
    lol i = v.size() / 2;
    multiset<lol> x;
    for (lol j = 0; j < i; j++)
    {
        x.insert(v[j]);
    }
    for (lol j = i; j < v.size(); j++)
    {
        auto it = x.upper_bound(v[j] / 2);
        if (it != x.begin())
        {
            it--;
            x.erase(it);
            ans--;
        }
    }
    cout << ans;

    return 0;
}