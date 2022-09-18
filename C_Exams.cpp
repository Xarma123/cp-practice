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
    pair<lol, lol> a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n);
    bool f = true;
    lol v = a[n - 1].second;
    for (lol i = n - 2; i >= 0; i--)
    {
        if (a[i].first <= v)
            break;
        else if (a[i].second <= v)
            v = min(v, a[i].second);
        else
        {
            f = false;
            break;
        }
    }
    if (f)
        cout << a[n - 1].second;
    else
        cout << a[n - 1].first;

    return 0;
}