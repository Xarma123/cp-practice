#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    pair<lol, lol> a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    vector<vector<lol>> op;
    lol m = 0, ans = a[n - 1].first - a[0].first;
    while (k--)
    {
        if (ans == 0)
            break;
        op.push_back({a[n - 1].second, a[0].second});
        a[n - 1].first--;
        a[0].first++;
        sort(a, a + n);
        if (ans > a[n - 1].first - a[0].first)
        {
            ans = a[n - 1].first - a[0].first;
            m = op.size();
        }
    }
    cout << ans << " " << m << endl;
    for (lol i = 0; i < m; i++)
    {
        cout << op[i][0]+1 << " " << op[i][1]+1 << endl;
    }

    return 0;
}