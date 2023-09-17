#include <bits/stdc++.h>
using namespace std;
#define lol long long
bool cmp(pair<lol, lol> a, pair<lol, lol> b)
{
    if (a.first > b.first)
        return true;
    if (a.first < b.first)
        return false;
    if (a.second < b.second)
        return true;
    return false;
}
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
        lol a1, a2, a3, a4;
        cin >> a1 >> a2 >> a3 >> a4;
        a[i].first = a1 + a2 + a3 + a4;
        a[i].second = i;
    }
    sort(a, a + n, cmp);
    for (lol i = 0; i < n; i++)
    {
        if (a[i].second == 0)
            cout << i + 1;
    }
}