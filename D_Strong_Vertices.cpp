#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n], b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<pair<lol, lol>> v;
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
            b[i] = a[i] - b[i];
            v.push_back({-b[i], i});
        }
        sort(v.begin(), v.end());
        lol j = 0;
        while (j < v.size() && v[j].first == v[0].first)
        {
            j++;
        }
        cout << j << '\n';
        for (lol i = 0; i < j; i++)
        {
            cout << v[i].second + 1 << " ";
        }
        cout << '\n';
    }
}