#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol sum, limit;
    cin >> sum >> limit;
    vector<pair<lol, lol>> x;
    for (lol i = 1; i <= limit; i++)
    {
        x.push_back({(i - (i & (i - 1))), i});
    }
    sort(x.rbegin(), x.rend());
    vector<lol> ans;
    for (lol i = 0; i < x.size(); i++)
    {
        if (sum - x[i].first >= 0)
        {
            sum -= x[i].first;
            ans.push_back(x[i].second);
        }
    }
    if (sum != 0)
        cout << -1;
    else
    {
        cout << ans.size() << endl;
        for (auto e : ans)
            cout << e << " ";
    }

    return 0;
}