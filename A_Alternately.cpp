#include <bits/stdc++.h>
using namespace std;
#define lol long long
float esp = 0.0001;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lol n;
    cin >> n;
    lol y[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> y[i];
    }
    vector<float> v;
    for (lol i = 0; i < n; i++)
    {
        v.push_back((float)v[i]);
        v.push_back((float)(v[i] - esp));
        v.push_back((float)(v[i] + esp));
    }
    sort(v.begin(), v.end());
    lol c[v.size()];
    memset(c, 0, sizeof(c));
    for (lol i = 1; i < n; i++)
    {
        lol l = min(y[i - 1], y[i]);
        lol r = max(y[i], y[i - 1]);
        int j1 = lower_bound(v.begin(), v.end(), l) - v.begin();
        lol j2 = upper_bound(v.begin(), v.end(), r) - v.begin();
        if (j1 < v.size())
            c[j1]++;
        if (j2 < v.size())
            c[j2]--;
    }
    for (lol i = 1; i < v.size(); i++)
    {
        c[i] += c[i - 1];
    }
    map<float, lol> mp;
    for (lol i = 1; i < n - 1; i++)
    {
        mp[v[i]]++;
    }
    lol ans = 0;
    for (lol i = 0; i < v.size(); i++)
    {
        c[i] -= mp[v[i]];
        ans = max(ans, c[i]);
    }
    cout << ans;

    return 0;
}
