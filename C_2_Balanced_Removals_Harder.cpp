#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<pair<lol, pair<lol, pair<lol, lol>>>> p;
    lol n;
    cin >> n;
    for (lol i = 0; i < n; i++)
    {
        lol x, y, z;
        cin >> x >> y >> z;
        p.push_back({x, {y, {z, i}}});
    }
    sort(p.begin(), p.end());
    for (lol i = 0; i < p.size(); i += 2)
    {
        cout << p[i].second.second.second + 1 << " " << p[i + 1].second.second.second + 1 << endl;
    }

    return 0;
}