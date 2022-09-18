#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol n;
vector<pair<long double, long double>> a;
bool check(long double t)
{
    long double seg1 = INT_MIN, seg2 = INT_MAX;
    for (lol i = 0; i < n; i++)
    {
        seg1 = max(seg1, (a[i].first - a[i].second * t));
        seg2 = min(seg2, (a[i].first + a[i].second * t));
    }
    return seg1 <= seg2;
}
int main()
{

    cin >> n;

    for (lol i = 0; i < n; i++)
    {
        long double a1, b;
        cin >> a1 >> b;
        a.push_back(make_pair(a1, b));
    }
    long double s = -1;
    long double e = 1e18;
    lol c = 100;
    while (c--)
    {
        long double m = (s + e) / 2;
        if (check(m))
            e = m;
        else
            s = m;
    } 
    cout<<setprecision(18)<<e;

    return 0;
}