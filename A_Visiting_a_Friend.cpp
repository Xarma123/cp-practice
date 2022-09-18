#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, m;
    cin >> n >> m;
    pair<lol, lol> a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n);
    lol l = a[0].first;
    lol r = a[0].second;
    for (lol i = 1; i < n; i++)
    {
        if (a[i].first > r)
            break;
        r = max(a[i].second, r);
    }
    if (l <= 0 && r >= m)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}