#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol m, n;
vector<pair<lol, pair<lol, lol>>> a;
bool check(lol t)
{
    lol b = 0;
    for (lol i = 0; i < n; i++)
    {
        lol s = a[i].first * a[i].second.first + a[i].second.second;
        b += t / s;
        s = t % s;
        if (s >= a[i].first * a[i].second.first)
        {
            b += a[i].second.first;
        }
        else
        {
            b += s / a[i].first;
        }
    }
    return b >= m;
}
int main()
{

    cin >> m >> n;

    for (lol i = 0; i < n; i++)
    {
        lol t, z, y;
        cin >> t >> z >> y;
        a.push_back(make_pair(t, make_pair(z, y)));
    }
    lol s = -1;
    lol e = 1e18;
    lol c = 100;
    while (c--)
    {
        lol m = (s + e) / 2;
        if (check(m))
            e = m;
        else
            s = m;
    }
    cout << e << endl;
    lol b;
    for (lol i = 0; i < n; i++)
    {
        b = 0;
        lol s = a[i].first * a[i].second.first + a[i].second.second;
        b += e / s;
        s = e % s;
        if (s >= a[i].first * a[i].second.first)
        {
            b += a[i].second.first;
        }
        else
        {
            b += s / a[i].first;
        }
        cout << b << " ";
    }

    return 0;
}