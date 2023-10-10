#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    vector<vector<lol>> a(n, vector<lol>(4));
    vector<lol> x, y;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
        if (a[i][0] == a[i][2] && a[i][1] == a[i][3])
        {
            x.push_back(a[i][0]);
            y.push_back(a[i][1]);
        }
        else if (a[i][0] == a[i][2])
        {
            x.push_back(a[i][0]);
        }
        else
        {
            y.push_back(a[i][1]);
        }
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    lol ans = 0;
    for (auto e : x)
    {
        ans += abs(e - x[x.size() / 2]);
    }
    for (auto e : y)
    {
        ans += abs(e - y[y.size() / 2]);
    }
    cout << ans;
}