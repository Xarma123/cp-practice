#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, t;
    cin >> n >> m >> t;
    lol a[n - 1];
    for (lol i = 0; i < n - 1; i++)
    {
        cin >> a[i];
    }
    vector<pair<lol, lol>> bonus;
    while (m--)
    {
        lol a, b;
        cin >> a >> b;
        bonus.push_back({a-1, b});
    }
    sort(bonus.begin(), bonus.end());
    lol i = 0, j = 0;
    while (i != n-1)
    {
        if (j < bonus.size() && bonus[j].first == i)
        {
            t += bonus[j].second;
            j++;
        }
        if (t <= a[i])
            break;
        else
        {
            t -= a[i];
            i++;
        }
    }
    if (i == n-1)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}