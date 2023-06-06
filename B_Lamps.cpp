#include <bits/stdc++.h>
using namespace std;
#define lol long long
bool cmp(pair<lol, lol> a, pair<lol, lol> b)
{
    if (a.first < b.first)
        return true;
    if (a.first > b.first)
        return false;
    if (a.second > b.second)
        return true;
    return false;
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        pair<lol, lol> a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i].first >> a[i].second;
        }
        sort(a, a + n, cmp);
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            lol j = i + 1;
            while (j < n && a[i].first == a[j].first)
                j++;
            for (lol k = i; k < j && k < i + a[i].first; k++)
            {
                ans += a[k].second;
            }
            i = j - 1;
        }
        cout << ans << '\n';
    }
}